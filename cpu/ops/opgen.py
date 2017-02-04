# Generate opcode functions from documentation.

import re

def main():
    opmapf = open('opmap.txt', 'r')
    opmaps = opmapf.read()
    opmap = opmaps.split('\r\n\r\n')
    for op in opmap:
        opa = op.splitlines()
        namem = opa[1].partition('|')[-1].rpartition('|')[0]
        namema = namem.split('|')
        name = namema[0].lower().strip()
        desc = namema[1].strip()
        opcode = opa[3].partition('(')[-1].rpartition(')')[0]
        fields = opa[3].split('|')
        fields = map(str.strip, fields)
        fields = filter(None, fields)
        print name
        print '\tdesc: ' + desc
        print '\topcode: ' + opcode
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
        cfc.append('#define OPCODE ' + str(hex(int(opcode))) + '\n\n')
        cfc.append('void ns4_vr4300i_' + name + '(void) {\n')
        cfc.append('\n}')
        opf.write(''.join(cfc))

main()
