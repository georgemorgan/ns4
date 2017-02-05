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
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("sub %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}