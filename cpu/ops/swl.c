/* swl.c - Store Word Left */

#include <vr4300i.h>

/*
  SWL rt, offset(base)
  store the most-significant part of a word anunaligned memory address.
  right[base+offset] = left(rt)
*/

#define OPCODE 0x2a

void ns4_vr4300i_swl(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("swl base, rt, offset, ");
}