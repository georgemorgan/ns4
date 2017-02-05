/* divu.c - DIVide Unsigned word */

#include <vr4300i.h>

/*
  DIVU rs, rt
  divide 32-bit unsigned integers.
  LO = rs / rt;     HI = rs MOD rt
*/

#define OPCODE 0x0

void ns4_vr4300i_divu(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t 0000 0000 00 = (inst() >> 0x6) & 0x3ff;
	uint32_t 011011 (27) = (inst() >> 0x0) & 0x3f;

	ns4_debug("divu rs, rt, ");
}