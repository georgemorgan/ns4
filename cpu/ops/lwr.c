/* lwr.c - Load Word Right */

#include <vr4300i.h>

/*
  LWR rt, offset( base )
  load the least-significant part of a word from anunaligned memory address as a signed value.
  right( rt ) = left[base+offset]
*/

#define OPCODE 0x26

void ns4_vr4300i_lwr(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	right(vr -> regs[rt]) = left[base+offset];

	ns4_debug("lwr 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}