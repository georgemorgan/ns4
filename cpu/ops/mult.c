/* mult.c - MULTiply word */

#include <vr4300i.h>

/*
  MULT rs, rt
  multiply 32-bit signed integers.
  LO = low(rs*rt);    HI = high(rs*rt)
*/

#define OPCODE 0x0

void ns4_vr4300i_mult(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t 0000 0000 00 = (inst() >> 0x6) & 0x3ff;
	uint32_t 011000 (24) = (inst() >> 0x0) & 0x3f;

	ns4_debug("mult rs, rt, ");
}