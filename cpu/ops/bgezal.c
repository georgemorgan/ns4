/* bgezal.c - Branch on Greater than or Equal Zero And Link */

#include <vr4300i.h>

/*
  BGEZAL rs, offset
  test a GPR then do a PC-relative conditional procedure call.
   Comment: BGEZAL r0, offset is equal a BAL offset
  branch if rs >= 0 (signed) (return address in ra)
*/

#define OPCODE 0x1

void ns4_vr4300i_bgezal(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("bgezal %s, 0x%x", regstrs[rs], offset);
}