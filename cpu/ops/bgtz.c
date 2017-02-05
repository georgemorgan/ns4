/* bgtz.c - Branch on Greater than Zero */

#include <vr4300i.h>

/*
  BGTZ rs, offset
  test a GPR then do a PC-relative conditional branch.
  branch if rs > 0 (signed)
*/

#define OPCODE 0x7

void ns4_vr4300i_bgtz(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 00000 = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("bgtz rs, offset, ");
}