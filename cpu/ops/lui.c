/* lui.c - Load Upper Immediate */

#include <vr4300i.h>

/*
  LUI rt, immediate
  load a constant inthe upper half of a word.
  rt = immediate * 10000h
*/

#define OPCODE 0xf

void ns4_vr4300i_lui(struct _vr4300i *vr) {
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t immediate = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("lui %s, 0x%x", regstrs[rt], immediate);
}