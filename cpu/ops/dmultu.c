/* dmultu.c - Doubleword MULTiply Unsigned */

#include <vr4300i.h>

/*
  DMULTU rs, rt
  multiply 64-bit unsigned integers.
  LO = low(rs*rt);  HI = high(rs*rt)
*/

#define OPCODE 0x0

void ns4_vr4300i_dmultu(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t 0000 0000 00 = (inst() >> 0x6) & 0x3ff;
	uint32_t 011101 (29) = (inst() >> 0x0) & 0x3f;

	ns4_debug("dmultu rs, rt, ");
}