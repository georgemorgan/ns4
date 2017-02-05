/* ori.c - OR Immediate */

#include <vr4300i.h>

/*
  ORI rt, rs, immediate
  do a bitwise logical OR with a constant.
   Comment: ORI rt, r0, imm is equal a LI rt, imm
  rt = ( rs OR immediate )
*/

#define OPCODE 0xd

void ns4_vr4300i_ori(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t immediate = (vr -> op >> 0x0) & 0xffff;

	vr -> regs[rt] = (vr -> regs[rs] | immediate);

	ns4_debug("ori %s, %s, 0x%x", regstrs[rs], regstrs[rt], immediate);
}