/* srav.c - Shift word Right Arithmetic Variable */

#include <vr4300i.h>

/*
  SRAV rd, rt, rs
  arithmetic right shift a word by a variable number of bits.
  rd = rt >> rs
*/

#define OPCODE 0x0

void ns4_vr4300i_srav(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	vr -> regs[rd] = vr -> regs[rt] >> vr -> regs[rs];

	ns4_debug("srav %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}