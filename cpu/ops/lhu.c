/* lhu.c - Load Halfword Unsigned */

#include <vr4300i.h>

/*
  LHU rt, offset(base)
  load a halfword from memory as an unsigned value.
  rt = halfword[base+offset]
*/

#define OPCODE 0x25

void ns4_vr4300i_lhu(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("lhu 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}