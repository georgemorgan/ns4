/* bnel.c - Branch on Not Equal Likely */

#include <vr4300i.h>

/*
  BNEL rs, rt, offset
  compare GPRs then do a PC-relative conditional branch;execute the delay slot only if the branch is taken.
   Comment: BNEL rs, r0, offset is equal a BNEZL rs, offset
  branch if rs <> rt
*/

#define OPCODE 0x15

void ns4_vr4300i_bnel(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("bnel rs, rt, offset, ");
}