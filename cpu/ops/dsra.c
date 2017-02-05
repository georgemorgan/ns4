/* dsra.c - Doubleword Shift Right Arithmetic */

#include <vr4300i.h>

/*
  DSRA rd, rt, sa
  arithmetic right shift a doubleword by a fixedamount -- 0 31 bits.
  rd = rt >> sa
*/

#define OPCODE 0x0

void ns4_vr4300i_dsra(struct _vr4300i *vr) {
	uint32_t 00000 = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t sa = (inst() >> 0x6) & 0x1f;
	uint32_t 111011 (59) = (inst() >> 0x0) & 0x3f;

	ns4_debug("dsra rt, rd, sa, ");
}