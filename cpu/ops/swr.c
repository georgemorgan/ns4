/* swr.c - Store Word Right */

#include <vr4300i.h>

/*
  SWR rt, offset( base )
  store the least-significant part of a word anunaligned memory address.
  left[base+offset] = right( rt )
*/

#define OPCODE 0x2e

void ns4_vr4300i_swr(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	left[base+offset] = right(vr -> regs[rt]);

	ns4_debug("swr 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}