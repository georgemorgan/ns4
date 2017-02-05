/* sdr.c - Store Doubleword Right */

#include <vr4300i.h>

/*
  SDR rt, offset(base)
  store the least-significant part of a doubleword toan unaligned memory address.
  left[base+offset] = right(rt)
*/

#define OPCODE 0x2d

void ns4_vr4300i_sdr(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("sdr 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}