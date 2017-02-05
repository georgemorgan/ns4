/* scd.c - Store Conditional Doubleword */

#include <vr4300i.h>

/*
  SCD rt, offset( base )
  store a doubleword memory complete an atomicread-modify-write.
*/

#define OPCODE 0x3c

void ns4_vr4300i_scd(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	/* no imp */;

	ns4_debug("scd 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}