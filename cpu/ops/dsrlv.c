/* dsrlv.c - Doubleword Shift Right Logical Variable */

#include <vr4300i.h>

/*
  DSRLV rd, rt, rs
  logical right shift a doubleword by a variable number of bits.
  rd = rt >> rs
*/

#define OPCODE 0x0

void ns4_vr4300i_dsrlv(struct _vr4300i *vr) {
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;
	uint32_t rs = (vr -> op >> 0x6) & 0x1f;

	ns4_debug("dsrlv rt, rd, rs, ");
}