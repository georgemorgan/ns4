/* bgtzl.c - Branch on Greater Than Zero Likely */

#include <vr4300i.h>

/*
  BGTZL rs, offset
  test a GPR then do a PC-relative conditional branch;execute the delay slot only if the branch is taken.
  branch if rs > 0 (signed)
*/

#define OPCODE 0x17

void ns4_vr4300i_bgtzl(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 00000 = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("bgtzl rs, offset, ");
}