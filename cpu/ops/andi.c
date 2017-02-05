/* andi.c - AND Immediate */

#include <vr4300i.h>

/*
  ANDI rt, rs, immediate
  do a bitwise logical AND with a constant.
  rt = (rs AND immediate)
*/

#define OPCODE 0xc

void ns4_vr4300i_andi(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t immediate = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("andi %s, %s, 0x%x", regstrs[rs], regstrs[rt], immediate);
}