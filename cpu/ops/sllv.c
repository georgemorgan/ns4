/* sllv.c - Shift word Left Logical Variable */

#include <vr4300i.h>

/*
  SLLV rd, rt, rs
  left shift a word by a variable number of bits.
  rd = rt << sa
*/

#define OPCODE 0x0

void ns4_vr4300i_sllv(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	vr -> regs[rd] = vr -> regs[rt] << vr -> regs[sa];

	ns4_debug("sllv %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}