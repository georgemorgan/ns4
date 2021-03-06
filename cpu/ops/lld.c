/* lld.c - Load Linked Doubleword */

#include <vr4300i.h>

/*
  LLD rt, offset( base )
  load a doubleword from memory for an atomic read-modify-write.
*/

#define OPCODE 0x34

void ns4_vr4300i_lld(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	/* no imp */;

	ns4_debug("lld 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}