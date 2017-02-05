/* dsrl.c - Doubleword Shift Right Logical */

#include <vr4300i.h>

/*
  DSRL rd, rt, sa
  logical right shift a doubleword by a fixed amount-- 0 31 bits.
  rd = rt >> sa
*/

#define OPCODE 0x0

void ns4_vr4300i_dsrl(struct _vr4300i *vr) {
	uint32_t 00000 = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t sa = (inst() >> 0x6) & 0x1f;
	uint32_t 111010 (58) = (inst() >> 0x0) & 0x3f;

	ns4_debug("dsrl rt, rd, sa, ");
}