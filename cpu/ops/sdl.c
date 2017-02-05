/* sdl.c - Store Doubleword Left */

#include <vr4300i.h>

/*
  SDL rt, offset(base)
  store the most-significant part of a doubleword toan unaligned memory address.
  right[base+offset] = left(rt)
*/

#define OPCODE 0x2c

void ns4_vr4300i_sdl(struct _vr4300i *vr) {
	uint32_t base = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t offset = (inst() >> 0x0) & 0xffff;

	ns4_debug("sdl base, rt, offset, ");
}