/* mult.c - MULTiply word */

#include <vr4300i.h>

/*
  MULT rs, rt
  multiply 32-bit signed integers.
  LO = low( rs*rt );    HI = high( rs*rt )
*/

#define OPCODE 0x0

void ns4_vr4300i_mult(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;

	LO = low(rs*rt); HI = high(rs*rt);

	ns4_debug("mult %s, %s", regstrs[rs], regstrs[rt]);
}