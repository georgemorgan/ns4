/* tnei.c - Trap if Not Equal Immediate */

#include <vr4300i.h>

/*
  TNEI rs, immediate
  compare a GPR a constant and do a conditional Trap.
  if rs <> immediate then trap
*/

#define OPCODE 0x1

void ns4_vr4300i_tnei(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 01110(14) = (inst() >> 0x10) & 0x1f;
	uint32_t immediate = (inst() >> 0x0) & 0xffff;

	ns4_debug("tnei rs, immediate, ");
}