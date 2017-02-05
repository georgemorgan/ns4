/* dmult.c - Doubleword MULTiply */

#include <vr4300i.h>

/*
  DMULT rs, rt
  multiply 64-bit signed integers.
  LO = low(rs*rt);  HI = high(rs*rt)
*/

#define OPCODE 0x0

void ns4_vr4300i_dmult(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;

	ns4_debug("dmult rs, rt, ");
}