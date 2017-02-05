/* addi.c - ADD Immediate word */

#include <vr4300i.h>

/*
  ADDI rt, rs, immediate
  add a constant a 32-bit integer.If overflow occurs, then trap.
  rt = rs + immediate
*/

#define OPCODE 0x8

void ns4_vr4300i_addi(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t immediate = (vr -> op >> 0x0) & 0xffff;

	vr -> regs[rt] = vr -> regs[rs] + immediate;

	ns4_debug("addi %s, %s, 0x%x", regstrs[rs], regstrs[rt], immediate);
}