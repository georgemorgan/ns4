# Generate opcode functions from documentation.

import re

def main():
    opmapf = open('opmap.txt', 'r')
    opmaps = opmapf.read()
    opmap = opmaps.split('\r\n\r\n')
    opst = []
    for op in opmap:
        opa = op.splitlines()
        namem = opa[1].partition('|')[-1].rpartition('|')[0]
        namema = namem.split('|')
        name = namema[0].lower().strip()
        desc = namema[1].strip()
        fields = opa[3].split('|')
        fields = map(str.strip, fields)
        fields = filter(None, fields)
        opcode = hex(int(fields[0][:6], 2))
        print name
        print '\tdesc: ' + desc
        print '\topcode: ' + str(opcode)
        opst.append((name, opcode))
        print '\tfields: ' + str(fields)
        fieldlens = opa[4].replace('-', ' ')
        fieldlens = re.sub(' +', ' ', fieldlens)
        fieldlens = fieldlens.split(' ')
        fieldlens = filter(None, fieldlens)
        print '\tlens: ' + str(fieldlens)
        opf = open(name + '.c', 'w')
        cfc = []
        cfc.append('/* ' + name + '.c - ' + desc + ' */\n\n')
        cfc.append('#include <vr4300i.h>\n\n')
        cfc.append('/*\n')
        for i in opa[5:]:
            cfc.append('  ' + i + '\n')
        cfc.append('*/\n\n')
        cfc.append('#define OPCODE ' + opcode + '\n\n')
        cfc.append('void ns4_vr4300i_' + name + '(struct _vr4300i *vr) {\n')
        offset = 6;
        for i in range(1, len(fields[1:]) + 1):
            ob = fields[i]
            width = int(fieldlens[i])
            cfc.append('\tuint32_t ' + ob + ' = (inst() >> ' + str(hex(32 - width - offset)) + ') & ' + str(hex(pow(2, width) - 1)) + ';\n')
            offset += width
        cfc.append('\n\tns4_debug("' + name + ' ')
        for i in fields[1:]:
            if i.isalpha():
                cfc.append(i + ', ')
        cfc.append('");\n')
        cfc.append('}')
        opf.write(''.join(cfc))
    opst = sorted(opst, key=lambda x: int(str(x[1]), 16))
#    for i in opst:
#        print i[0] + '(' + str(i[1]) + ')'

main()
