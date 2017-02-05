/* jal.c - Jump And Link */

#include <vr4300i.h>

/*
  JAL target
  procedure call within the current 256 MB aligned region.
  return address in ra
*/

#define OPCODE 0x3

void ns4_vr4300i_jal(struct _vr4300i *vr) {
	uint32_t instr_index = (inst() >> 0x0) & 0x3ffffff;

	ns4_debug("jal ");
}