/* bgtz.c - Branch on Greater than Zero */

#include <vr4300i.h>

/*
  BGTZ rs, offset
  test a GPR then do a PC-relative conditional branch.
  branch if rs > 0 (signed)
*/

#define OPCODE 0x7

void ns4_vr4300i_bgtz(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("bgtz %s, 0x%x", regstrs[rs], offset);
}