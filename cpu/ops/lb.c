/* lb.c - Load Byte */

#include <vr4300i.h>

/*
  LB rt, offset(base)
  load a byte from memory as a signed value.
  rt = byte[base+offset]
*/

#define OPCODE 0x20

void ns4_vr4300i_lb(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("lb 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}