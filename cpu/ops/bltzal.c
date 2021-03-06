/* bltzal.c - Branch on Less Than Zero And Link */

#include <vr4300i.h>

/*
  BLTZAL rs, offset
  test a GPR then do a PC-relative conditional procedure call.
  branch if rs < 0 ( signed ) ( return address in ra )
*/

#define OPCODE 0x1

void ns4_vr4300i_bltzal(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	if (vr -> regs[rs] < 0 (vr -> regs[return] address in vr -> regs[ra])) {
		 vr -> pc += offset; 
		vr -> lr = vr -> pc; 
	};

	ns4_debug("bltzal %s, 0x%x", regstrs[rs], offset);
}