/* beq.c - Branch on EQual */

#include <vr4300i.h>

/*
  BEQ rs, rt, offset
  compare GPRs then do a PC-relative conditional branch.
   Comment: BEQ rs, r0, offset is equal a BEQZ rs, offsetBEQ r0, r0, offset is equal a B offset
  branch if rs = rt
*/

#define OPCODE 0x4

void ns4_vr4300i_beq(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("beq rs, rt, offset, ");
}