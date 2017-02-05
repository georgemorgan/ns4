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
        #print name
        #print '\tdesc: ' + desc
        #print '\topcode: ' + str(opcode)
        #print '\tfields: ' + str(fields)
        fieldlens = opa[4].replace('-', ' ')
        fieldlens = re.sub(' +', ' ', fieldlens)
        fieldlens = fieldlens.split(' ')
        fieldlens = filter(None, fieldlens)
        #print '\tlens: ' + str(fieldlens)
        opst.append((name, opcode, fields))
        opf = open(name + '.c', 'w')
        cfc = []
        cfc.append('/* ' + name + '.c - ' + desc + ' */\n\n')
        cfc.append('#include <vr4300i.h>\n\n')
        cfc.append('/*\n')
        oppsu = opa[5:][-1] if (len(opa[5:]) > 2) else '/* no imp */'
        for i in opa[5:]:
            cfc.append('  ' + i + '\n')
        cfc.append('*/\n\n')
        cfc.append('#define OPCODE ' + opcode + '\n\n')
        cfc.append('void ns4_vr4300i_' + name + '(struct _vr4300i *vr) {\n')
        offset = 6;
        for i in range(1, len(fields[1:]) + 1):
            ob = fields[i]
            width = int(fieldlens[i])
            if ob.isalpha():
                cfc.append('\tuint32_t ' + ob + ' = (vr -> op >> ' + str(hex(32 - width - offset)) + ') & ' + str(hex(pow(2, width) - 1)) + ';\n')
            offset += width

        # User code begin

        oppsu = oppsu.replace('AND', '&')
        oppsu = oppsu.replace('OR', '|')
        oppsu = oppsu.replace('( signed )', '')
        oppsu = oppsu.replace('<>', '!=')
        oppsua = oppsu.split()

        # Add logic for parsing conditionals.
        if oppsua[0] == 'branch':
            if '=' in oppsua:
                eqi = oppsua.index('=')
                oppsua[eqi] = '=='
            oppsua[1] = 'if ('
            oppsua.append(') {\n\t\t')
            oppsua.append('vr -> pc += offset;')
            if name.startswith('bl'):
                oppsua.append('\n\t\tvr -> lr = vr -> pc;')
            oppsua.append('\n\t}')
            oppsua.remove(oppsua[0])

        print oppsua
        for i, s in enumerate(oppsua):
            if s.isalpha() and (s.startswith('r') or s.startswith('s')) :
                oppsua[i] = 'vr -> regs[' + s + ']'
        oppsuas = ' '.join(oppsua).replace('( ', '(').replace(' )', ')')
        cfc.append('\n\t' + oppsuas + ';\n')

        # User code end

        cfc.append('\n\tns4_debug("' + name + ' ')
        format = []
        for i in fields[1:]:
            if i.isalpha():
                if (i.startswith('r')):
                    dstr = '%s'
                else:
                    dstr = '0x%x'
                format.append(dstr)
        cfc.append(', '.join(format) + '"')
        params = []
        for i in fields[1:]:
            if i.isalpha():
                if (i.startswith('r')):
                    desc = 'regstrs[' + i + ']'
                else:
                    desc = i
                params.append(desc)
        if len(params):
            cfc.append(', ' + ', '.join(params))
        cfc.append(');\n')
        cfc.append('}')
        opf.write(''.join(cfc))
    opst = sorted(opst, key=lambda x: int(str(x[1]), 16))
    opdict = {}
    for i in opst:
        opdict[i[1]] = []
    for i in opst:
        opdict[i[1]].append(i)
    dupes = []
    uniq = []
    for key, i in opdict.items():
        if len(i) > 1:
            dupes.append((key, i))
        else:
            uniq += i
    csw = open('switch.c', 'w')
    csf = []
    csf.append('/* switch.c - Switches through CPU opcodes. */\n\n')
    csf.append('#include <vr4300i.h>\n\n')
    csf.append('void vr4300i_exec(struct _vr4300i *vr) {\n')
    csf.append('\t/* unique opcodes. */\n')
    csf.append('\tswitch((vr -> op >> 0x1A) & 0x3F) {\n')
    for i in uniq:
        csf.append('\t\tcase ' + str(i[1]) + ':\n')
        csf.append('\t\t\tns4_vr4300i_' + i[0] + '(vr);\n')
        csf.append('\t\t\tbreak;\n')
    csf.append('\n\t\t/* class opcodes. */\n')
    for i in dupes:
        csf.append('\t\tcase ' + str(i[0]) + ':\n')
        csf.append('\t\t\tgoto class_' + str(i[0]) + ';\n')
        csf.append('\t\t\tbreak;\n')
    csf.append('\t\tdefault:\n\t\t\tns4_assert(0, NS4_WARN, "Invalid opcode (0x%02x).\\n", ((vr -> op >> 0x1A) & 0x3F));\n\t\t\tbreak;\n')
    csf.append('\t}\n')
    csf.append('\treturn;\n\n')
    for i in dupes:
        optype = int(i[0], 16)
        csf.append('class_' + str(hex(optype)) + ':\n')
        csf.append('\t/* ' + str(i[0]) + ' class opcodes. */\n')
        if (optype == 0x1):
            opshift = '(vr -> op >> 0x10) & 0x1F'
        if (optype == 0x0):
            opshift = '(vr -> op) & 0x3F'
        if (optype == 0x10):
            opshift = '(vr -> op) & 0x3F'   
        csf.append('\tswitch(' + opshift + ') {\n')
        for j in i[1]:
            if (optype == 0x1):
                subcode = int(j[2][2][:5], 2)
            if (optype == 0x0):
                subcode = int(j[2][-1][:6], 2)
            if (optype == 0x10):
                subcode = int(j[2][-1].replace(' ', '')[:6], 2) 
            csf.append('\t\tcase ' + str(hex(subcode)) + ':\n')
            csf.append('\t\t\tns4_vr4300i_' + j[0] + '(vr);\n')
            csf.append('\t\t\tbreak;\n')
        csf.append('\t}\n')
        csf.append('\treturn;\n\n')
    csf.append('}\n\n')
    csw.write(''.join(csf))

    print '\nTotal opcodes: ' + str(len(opst))

main()
