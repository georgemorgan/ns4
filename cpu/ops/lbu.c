/* lbu.c - Load Byte Unsigned */

#include <vr4300i.h>

/*
  LBU rt, offset( base )
  load a byte from memory as an unsigned value.
  rt = byte[base+offset]
*/

#define OPCODE 0x24

void ns4_vr4300i_lbu(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	vr -> regs[rt] = byte[base+offset];

	ns4_debug("lbu 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}