/* beql.c - Branch on EQual Likely */

#include <vr4300i.h>

/*
  BEQL rs, rt, offset
  compare GPRs then do a PC-relative conditional branch;execute the delay slot only if the branch is taken.
   Comment: BEQL rs, r0, offset is equal a BEQZL rs, offset
  branch if rs = rt
*/

#define OPCODE 0x14

void ns4_vr4300i_beql(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	if (vr -> regs[rs] == vr -> regs[rt]) {
		 vr -> pc += offset; 
	};

	ns4_debug("beql %s, %s, 0x%x", regstrs[rs], regstrs[rt], offset);
}