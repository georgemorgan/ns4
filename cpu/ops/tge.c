/* tge.c - Trap if Greater or Equal */

#include <vr4300i.h>

/*
  TGE rs, rt
  compare GPRs and do a conditional Trap.
  if rs >= rt then trap
*/

#define OPCODE 0x0

void ns4_vr4300i_tge(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t code = (vr -> op >> 0x6) & 0x3ff;

	ns4_debug("tge %s, %s, 0x%x", regstrs[rs], regstrs[rt], code);
}