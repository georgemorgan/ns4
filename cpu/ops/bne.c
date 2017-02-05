/* bne.c - Branch on Not Equal */

#include <vr4300i.h>

/*
  BNE rs, rt, offset
  compare GPRs then do a PC-relative conditional branch.
   Comment: BNE rs, r0, offset is equal a BNEZ rs, offset
  branch if rs <> rt
*/

#define OPCODE 0x5

void ns4_vr4300i_bne(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("bne rs, rt, offset, ");
}