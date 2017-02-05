/* sdl.c - Store Doubleword Left */

#include <vr4300i.h>

/*
  SDL rt, offset(base)
  store the most-significant part of a doubleword toan unaligned memory address.
  right[base+offset] = left(rt)
*/

#define OPCODE 0x2c

void ns4_vr4300i_sdl(struct _vr4300i *vr) {
	uint32_t base = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t offset = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("sdl 0x%x, %s, 0x%x", base, regstrs[rt], offset);
}