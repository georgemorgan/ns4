/* blez.c - Branch on Less than or Equal Zero */

#include <vr4300i.h>

/*
  BLEZ rs, offset
  test a GPR then do a PC-relative conditional branch.
  branch if rs <= 0 (signed)
*/

#define OPCODE 0x6

void ns4_vr4300i_blez(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("blez %s, 0x%x", regstrs[rs], offset);
}