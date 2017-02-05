/* tltu.c - Trap if Less Than Unsigned */

#include <vr4300i.h>

/*
  TLTU rs, rt
  compare GPRs and do a conditional Trap.
  if rs < rt then trap
*/

#define OPCODE 0x0

void ns4_vr4300i_tltu(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t code = (inst() >> 0x6) & 0x3ff;
	uint32_t 110011 (51) = (inst() >> 0x0) & 0x3f;

	ns4_debug("tltu rs, rt, code, ");
}