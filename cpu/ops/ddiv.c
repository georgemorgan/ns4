/* ddiv.c - Doubleword DIVide */

#include <vr4300i.h>

/*
  DDIV rs, rt
  divide 64-bit signed integers.
  LO = rs / rt;     HI = rs MOD rt
*/

#define OPCODE 0x0

void ns4_vr4300i_ddiv(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;

	ns4_debug("ddiv %s, %s", regstrs[rs], regstrs[rt]);
}