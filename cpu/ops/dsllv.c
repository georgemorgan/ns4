/* dsllv.c - Doubleword Shift Left Logical Variable */

#include <vr4300i.h>

/*
  DSLLV rd, rt, rs
  left shift a doubleword by a variable number of bits.
  rd = rt << rs
*/

#define OPCODE 0x0

void ns4_vr4300i_dsllv(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("dsllv %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}