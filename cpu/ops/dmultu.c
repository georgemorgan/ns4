/* dmultu.c - Doubleword MULTiply Unsigned */

#include <vr4300i.h>

/*
  DMULTU rs, rt
  multiply 64-bit unsigned integers.
  LO = low(rs*rt);  HI = high(rs*rt)
*/

#define OPCODE 0x0

void ns4_vr4300i_dmultu(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;

	ns4_debug("dmultu %s, %s", regstrs[rs], regstrs[rt]);
}