/* tlt.c - Trap if Less Than */

#include <vr4300i.h>

/*
  TLT rs, rt
  compare GPRs and do a conditional Trap.
  if rs < rt then trap
*/

#define OPCODE 0x0

void ns4_vr4300i_tlt(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t code = (inst() >> 0x6) & 0x3ff;
	uint32_t 110010 (50) = (inst() >> 0x0) & 0x3f;

	ns4_debug("tlt rs, rt, code, ");
}