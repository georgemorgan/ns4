/* ldr.c - Load Doubleword Right */

#include <vr4300i.h>

/*
  LDR rt, offset(base)
  load the least-significant part of a doubleword froman unaligned memory address.
  right(rt) = left[base+offset]
*/

#define OPCODE 0x1b

void ns4_vr4300i_ldr(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("ldr base, rt, offset, ");
}