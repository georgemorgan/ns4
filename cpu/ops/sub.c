/* sub.c - SUBtract word */

#include <vr4300i.h>

/*
  SUB rd, rs, rt
  subtract 32-bit integers. If overflow occurs, then trap.
   Comment: SUB rd, r0, rt is equal a NEG rd, rt
  rd = rs - rt
*/

#define OPCODE 0x0

void ns4_vr4300i_sub(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 100010 (34) = (inst() >> 0x0) & 0x3f;

	ns4_debug("sub rs, rt, rd, ");
}