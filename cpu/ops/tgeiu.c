/* tgeiu.c - Trap if Greater or Equal Immediate Unsigned */

#include <vr4300i.h>

/*
  TGEIU rs, immediate
  compare a GPR a constant and do a conditional Trap.
  if rs >= immediate then trap
*/

#define OPCODE 0x1

void ns4_vr4300i_tgeiu(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t immediate = (vr -> op >> 0x0) & 0xffff;

	if vr -> regs[rs] >= immediate then trap;

	ns4_debug("tgeiu %s, 0x%x", regstrs[rs], immediate);
}