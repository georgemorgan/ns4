/* dsll32.c - Doubleword Shift Left Logical +32 */

#include <vr4300i.h>

/*
  DSLL32 rd, rt, sa
  left shift a doubleword by a fixed amount -- 32 63 bits.
  rd = rt << (sa+32)
*/

#define OPCODE 0x0

void ns4_vr4300i_dsll32(struct _vr4300i *vr) {
	uint32_t 00000 = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t sa = (inst() >> 0x6) & 0x1f;
	uint32_t 111100 (60) = (inst() >> 0x0) & 0x3f;

	ns4_debug("dsll32 rt, rd, sa, ");
}