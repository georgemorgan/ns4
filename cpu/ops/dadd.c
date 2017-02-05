/* dadd.c - Doubleword ADD */

#include <vr4300i.h>

/*
  DADD rd, rs, rt
  add 64-bit integers. If overflow occurs, then trap.
  rd = rs + rt
*/

#define OPCODE 0x0

void ns4_vr4300i_dadd(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 101100 (44) = (inst() >> 0x0) & 0x3f;

	ns4_debug("dadd rs, rt, rd, ");
}