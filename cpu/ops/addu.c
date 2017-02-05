/* addu.c - ADD Unsigned word */

#include <vr4300i.h>

/*
  ADDU rd, rs, rt
  add 32-bit integers.
  rd = rs + rt
*/

#define OPCODE 0x0

void ns4_vr4300i_addu(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	vr -> regs[rd] = vr -> regs[rs] + vr -> regs[rt];

	ns4_debug("addu %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}