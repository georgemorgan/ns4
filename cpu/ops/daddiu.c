/* daddiu.c - Doubleword ADD Immediate Unsigned */

#include <vr4300i.h>

/*
  DADDIU rt, rs, immediate
  add a constant a 64-bit integer.
  rt = rs + immediate
*/

#define OPCODE 0x19

void ns4_vr4300i_daddiu(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t immediate = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("daddiu %s, %s, 0x%x", regstrs[rs], regstrs[rt], immediate);
}