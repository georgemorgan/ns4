/* ddiv.c - Doubleword DIVide */

#include <vr4300i.h>

/*
  DDIV rs, rt
  divide 64-bit signed integers.
  LO = rs / rt;     HI = rs MOD rt
*/

#define OPCODE 0x0

void ns4_vr4300i_ddiv(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t 0000 0000 00 = (inst() >> 0x6) & 0x3ff;
	uint32_t 011110 (30) = (inst() >> 0x0) & 0x3f;

	ns4_debug("ddiv rs, rt, ");
}