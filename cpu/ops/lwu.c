/* lwu.c - Load Word Unsigned */

#include <vr4300i.h>

/*
  LWU rt, offset(base)
  load a word from memory as an unsigned value.
  rt = word[base+offset]
*/

#define OPCODE 0x27

void ns4_vr4300i_lwu(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("lwu base, rt, offset, ");
}