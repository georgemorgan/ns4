/* ld.c - Load Doubleword */

#include <vr4300i.h>

/*
  LD rt, offset(base)
  load a doubleword from memory.
  rt = doubleword[base+offset]
*/

#define OPCODE 0x37

void ns4_vr4300i_ld(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("ld base, rt, offset, ");
}