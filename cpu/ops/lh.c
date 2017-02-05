/* lh.c - Load Halfword */

#include <vr4300i.h>

/*
  LH rt, offset( base )
  load a halfword from memory as a signed value.
  rt = halfword[base+offset]
*/

#define OPCODE 0x21

void ns4_vr4300i_lh(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	vr -> regs[rt] = halfword[base+offset];

	ns4_debug("lh 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}