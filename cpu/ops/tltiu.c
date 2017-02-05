/* tltiu.c - Trap if Less Than Immediate Unsigned */

#include <vr4300i.h>

/*
  TLTIU rs, immediate
  compare a GPR a constant and do a conditional Trap.
  if rs < immediate then trap
*/

#define OPCODE 0x1

void ns4_vr4300i_tltiu(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t immediate = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("tltiu %s, 0x%x", regstrs[rs], immediate);
}