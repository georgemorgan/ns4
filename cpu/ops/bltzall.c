/* bltzall.c - Branch on Less Than Zero And Link Likely */

#include <vr4300i.h>

/*
  BLTZALL rs, offset
  test a GPR then do a PC-relative conditional procedurecall; execute the delay slot only if the branch is taken.
  branch if rs < 0 (signed) (return address in ra)
*/

#define OPCODE 0x1

void ns4_vr4300i_bltzall(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 10010 = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("bltzall rs, offset, ");
}