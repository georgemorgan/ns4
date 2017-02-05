/* sh.c - Store Halfword */

#include <vr4300i.h>

/*
  SH rt, offset(base)
  store a halfword memory.
  halfword[base+offset] = rt
*/

#define OPCODE 0x29

void ns4_vr4300i_sh(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("sh base, rt, offset, ");
}