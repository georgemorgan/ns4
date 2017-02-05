/* daddi.c - Doubleword ADD Immediate */

#include <vr4300i.h>

/*
  DADDI rt, rs, immediate
  add a constant a 64-bit integer.If overflow occurs, then trap.
  rt = rs + immediate
*/

#define OPCODE 0x18

void ns4_vr4300i_daddi(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t immediate = (inst() >> 0x0) & 0xffff;

	ns4_debug("daddi rs, rt, immediate, ");
}