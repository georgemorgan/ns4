/* cache.c - CACHE */

#include <vr4300i.h>

/*
  CACHE op, offset(base)
  The 16-bit offset is sign-extended and added the contents ofgeneral register base form a virtual address. The virtualaddress is translated a physical address using the TLB, and the5-bit sub-opcode specifies a cache operation for that address.
*/

#define OPCODE 0x2f

void ns4_vr4300i_cache(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t op = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("cache base, op, offset, ");
}