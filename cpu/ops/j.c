/* j.c - Jump */

#include <vr4300i.h>

/*
  J target
  branch within the current 256 MB aligned region.
*/

#define OPCODE 0x2

void ns4_vr4300i_j(struct _vr4300i *vr) {
	uint32_t instr_index = (inst() >> 0x0) & 0x3ffffff;

	ns4_debug("j ");
}