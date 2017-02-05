/* ld.c - Load Doubleword */

#include <vr4300i.h>

/*
  LD rt, offset( base )
  load a doubleword from memory.
  rt = doubleword[base+offset]
*/

#define OPCODE 0x37

void ns4_vr4300i_ld(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	vr -> regs[rt] = doubleword[base+offset];

	ns4_debug("ld 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}