/* dadd.c - Doubleword ADD */

#include <vr4300i.h>

/*
  DADD rd, rs, rt
  add 64-bit integers. If overflow occurs, then trap.
  rd = rs + rt
*/

#define OPCODE 0x0

void ns4_vr4300i_dadd(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("dadd rs, rt, rd, ");
}