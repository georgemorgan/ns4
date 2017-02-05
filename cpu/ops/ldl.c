/* ldl.c - Load Doubleword Left */

#include <vr4300i.h>

/*
  LDL rt, offset(base)
  load the most-significant part of a doubleword froman unaligned memory address.
  left(rt) = right[base+offset]
*/

#define OPCODE 0x1a

void ns4_vr4300i_ldl(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("ldl 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}