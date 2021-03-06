/* bgez.c - Branch on Greater than or Equal Zero */

#include <vr4300i.h>

/*
  BGEZ rs, offset
  test a GPR then do a PC-relative conditional branch.
  branch if rs >= 0 ( signed )
*/

#define OPCODE 0x1

void ns4_vr4300i_bgez(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	if (vr -> regs[rs] >= 0) {
		 vr -> pc += offset; 
	};

	ns4_debug("bgez %s, 0x%x", regstrs[rs], offset);
}