/* lld.c - Load Linked Doubleword */

#include <vr4300i.h>

/*
  LLD rt, offset(base)
  load a doubleword from memory for an atomic read-modify-write.
*/

#define OPCODE 0x34

void ns4_vr4300i_lld(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("lld base, rt, offset, ");
}