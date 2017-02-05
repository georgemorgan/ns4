/* swr.c - Store Word Right */

#include <vr4300i.h>

/*
  SWR rt, offset(base)
  store the least-significant part of a word anunaligned memory address.
  left[base+offset] = right(rt)
*/

#define OPCODE 0x2e

void ns4_vr4300i_swr(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("swr base, rt, offset, ");
}