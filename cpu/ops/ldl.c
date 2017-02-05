/* ldl.c - Load Doubleword Left */

#include <vr4300i.h>

/*
  LDL rt, offset(base)
  load the most-significant part of a doubleword froman unaligned memory address.
  left(rt) = right[base+offset]
*/

#define OPCODE 0x1a

void ns4_vr4300i_ldl(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("ldl base, rt, offset, ");
}