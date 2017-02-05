/* dsub.c - Doubleword SUBtract */

#include <vr4300i.h>

/*
  DSUB rd, rs, rt
  subtract 64-bit integers; trap if overflow.
  rd = rs - rt
*/

#define OPCODE 0x0

void ns4_vr4300i_dsub(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 101110 (46) = (inst() >> 0x0) & 0x3f;

	ns4_debug("dsub rs, rt, rd, ");
}