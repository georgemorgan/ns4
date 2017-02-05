/* bgezall.c - Branch on Greater than or Equal Zero And Link Likely */

#include <vr4300i.h>

/*
  BGEZALL rs, offset
  test a GPR then do a PC-relative conditional procedure call;execute the delay slot only if the branch is taken.
  branch if rs >= 0 ( signed ) ( return address in ra )
*/

#define OPCODE 0x1

void ns4_vr4300i_bgezall(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	if (vr -> regs[rs] >= 0 (vr -> regs[return] address in vr -> regs[ra])) {
		 vr -> pc += offset; 
	};

	ns4_debug("bgezall %s, 0x%x", regstrs[rs], offset);
}