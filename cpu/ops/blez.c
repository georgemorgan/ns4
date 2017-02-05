/* blez.c - Branch on Less than or Equal Zero */

#include <vr4300i.h>

/*
  BLEZ rs, offset
  test a GPR then do a PC-relative conditional branch.
  branch if rs <= 0 (signed)
*/

#define OPCODE 0x6

void ns4_vr4300i_blez(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 00000 = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("blez rs, offset, ");
}