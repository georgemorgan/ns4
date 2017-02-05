/* lh.c - Load Halfword */

#include <vr4300i.h>

/*
  LH rt, offset(base)
  load a halfword from memory as a signed value.
  rt = halfword[base+offset]
*/

#define OPCODE 0x21

void ns4_vr4300i_lh(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("lh base, rt, offset, ");
}