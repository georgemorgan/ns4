/* lwu.c - Load Word Unsigned */

#include <vr4300i.h>

/*
  LWU rt, offset( base )
  load a word from memory as an unsigned value.
  rt = word[base+offset]
*/

#define OPCODE 0x27

void ns4_vr4300i_lwu(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	vr -> regs[rt] = word[base+offset];

	ns4_debug("lwu 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}