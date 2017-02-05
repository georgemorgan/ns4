/* sb.c - Store Byte */

#include <vr4300i.h>

/*
  SB rt, offset(base)
  store a byte memory.
  byte[base+offset] = rt
*/

#define OPCODE 0x28

void ns4_vr4300i_sb(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("sb 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}