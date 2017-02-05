/* ll.c - Load Linked Word */

#include <vr4300i.h>

/*
  LL rt, offset(base)
  load a word from memory for an atomic read-modify-write.
*/

#define OPCODE 0x30

void ns4_vr4300i_ll(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("ll base, rt, offset, ");
}