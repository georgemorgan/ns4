/* subu.c - SUBtract Unsigned word */

#include <vr4300i.h>

/*
  SUBU rd, rs, rt
  subtract 32-bit integers. No trap on overflow.
   Comment: SUBU rd, r0, rs is equal a NEGU rd, rs
  rd = rs - rt
*/

#define OPCODE 0x0

void ns4_vr4300i_subu(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("subu %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}