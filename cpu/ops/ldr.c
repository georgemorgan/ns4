/* ldr.c - Load Doubleword Right */

#include <vr4300i.h>

/*
  LDR rt, offset( base )
  load the least-significant part of a doubleword froman unaligned memory address.
  right( rt ) = left[base+offset]
*/

#define OPCODE 0x1b

void ns4_vr4300i_ldr(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	right(vr -> regs[rt]) = left[base+offset];

	ns4_debug("ldr 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}