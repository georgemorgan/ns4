/* subu.c - SUBtract Unsigned word */

#include <vr4300i.h>

/*
  SUBU rd, rs, rt
  subtract 32-bit integers. No trap on overflow.
   Comment: SUBU rd, r0, rs is equal a NEGU rd, rs
  rd = rs - rt
*/

#define OPCODE 0x0

void ns4_vr4300i_subu(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 100011 (35) = (inst() >> 0x0) & 0x3f;

	ns4_debug("subu rs, rt, rd, ");
}