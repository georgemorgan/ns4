/* dsub.c - Doubleword SUBtract */

#include <vr4300i.h>

/*
  DSUB rd, rs, rt
  subtract 64-bit integers; trap if overflow.
  rd = rs - rt
*/

#define OPCODE 0x0

void ns4_vr4300i_dsub(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("dsub rs, rt, rd, ");
}