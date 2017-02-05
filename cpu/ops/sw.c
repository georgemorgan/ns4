/* sw.c - Store Word */

#include <vr4300i.h>

/*
  SW rt, offset(base)
  store a word memory.
  word[base+offset] = rt
*/

#define OPCODE 0x2b

void ns4_vr4300i_sw(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("sw base, rt, offset, ");
}