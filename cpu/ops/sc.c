/* sc.c - Store Conditional Word */

#include <vr4300i.h>

/*
  SC rt, offset( base )
  store a word memory complete an atomic read-modify-write.
*/

#define OPCODE 0x38

void ns4_vr4300i_sc(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	/* no imp */;

	ns4_debug("sc 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}