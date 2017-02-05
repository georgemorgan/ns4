/* blezl.c - Branch on Less than or Equal Zero Likely */

#include <vr4300i.h>

/*
  BLEZL rs, offset
  test a GPR then do a PC-relative conditional branch;execute the delay slot only if the branch is taken.
  branch if rs <= 0 (signed)
*/

#define OPCODE 0x16

void ns4_vr4300i_blezl(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("blezl rs, offset, ");
}