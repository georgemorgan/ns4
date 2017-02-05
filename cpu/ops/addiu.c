/* addiu.c - ADD Immediate Unsigned word */

#include <vr4300i.h>

/*
  ADDIU rt, rs, immediate
  add a constant a 32-bit integer.
  rt = rs + immediate
*/

#define OPCODE 0x9

void ns4_vr4300i_addiu(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t immediate = (inst() >> 0x0) & 0xffff;

	ns4_debug("addiu rs, rt, immediate, ");
}