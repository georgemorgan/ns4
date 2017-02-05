/* teqi.c - Trap if EQual Immediate */

#include <vr4300i.h>

/*
  TEQI rs, immediate
  compare a GPR a constant and do a conditional Trap.
  if rs = immediate then trap
*/

#define OPCODE 0x1

void ns4_vr4300i_teqi(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 01100(12) = (inst() >> 0x10) & 0x1f;
	uint32_t immediate = (inst() >> 0x0) & 0xffff;

	ns4_debug("teqi rs, immediate, ");
}