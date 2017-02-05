/* lw.c - Load Word */

#include <vr4300i.h>

/*
  LW rt, offset(base)
  load a word from memory as a signed value.
  rt = word[base+offset]
*/

#define OPCODE 0x23

void ns4_vr4300i_lw(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("lw base, rt, offset, ");
}