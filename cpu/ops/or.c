/* or.c - OR */

#include <vr4300i.h>

/*
  OR rd, rs, rt
  do a bitwise logical OR.
  rd = ( rs OR rt )
*/

#define OPCODE 0x0

void ns4_vr4300i_or(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	vr -> regs[rd] = (vr -> regs[rs] | vr -> regs[rt]);

	ns4_debug("or %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}