/* dsrav.c - Doubleword Shift Right Arithmetic Variable */

#include <vr4300i.h>

/*
  DSRAV rd, rt, rs
  arithmetic right shift a doubleword by a variablenumber of bits.
  rd = rt >> rs
*/

#define OPCODE 0x0

void ns4_vr4300i_dsrav(struct _vr4300i *vr) {
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;
	uint32_t rs = (vr -> op >> 0x6) & 0x1f;

	vr -> regs[rd] = vr -> regs[rt] >> vr -> regs[rs];

	ns4_debug("dsrav %s, %s, %s", regstrs[rt], regstrs[rd], regstrs[rs]);
}