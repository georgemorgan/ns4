/* tgeiu.c - Trap if Greater or Equal Immediate Unsigned */

#include <vr4300i.h>

/*
  TGEIU rs, immediate
  compare a GPR a constant and do a conditional Trap.
  if rs >= immediate then trap
*/

#define OPCODE 0x1

void ns4_vr4300i_tgeiu(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 01001 (9) = (inst() >> 0x10) & 0x1f;
	uint32_t immediate = (inst() >> 0x0) & 0xffff;

	ns4_debug("tgeiu rs, immediate, ");
}