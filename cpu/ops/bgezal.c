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
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 10001(17) = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("bgezal rs, offset, ");
}