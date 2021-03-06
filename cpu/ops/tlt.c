/* tlt.c - Trap if Less Than */

#include <vr4300i.h>

/*
  TLT rs, rt
  compare GPRs and do a conditional Trap.
  if rs < rt then trap
*/

#define OPCODE 0x0

void ns4_vr4300i_tlt(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t code = (vr -> op >> 0x6) & 0x3ff;

	if vr -> regs[rs] < vr -> regs[rt] then trap;

	ns4_debug("tlt %s, %s, 0x%x", regstrs[rs], regstrs[rt], code);
}