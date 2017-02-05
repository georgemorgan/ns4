/* add.c - ADD word */

#include <vr4300i.h>

/*
  ADD rd, rs, rt
  add 32-bit integers. If overflow occurs, then trap.
   Comment: ADD rd, r0, rs is equal a MOVE rd, rs
  rd = rs + rt
*/

#define OPCODE 0x0

void ns4_vr4300i_add(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("add %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}