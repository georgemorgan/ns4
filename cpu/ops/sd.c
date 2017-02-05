/* sd.c - Store Doubleword */

#include <vr4300i.h>

/*
  SD rt, offset( base )
  store a doubleword memory.
  doulbeword[base+offset] = rt
*/

#define OPCODE 0x3f

void ns4_vr4300i_sd(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	doulbeword[base+offset] = vr -> regs[rt];

	ns4_debug("sd 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}