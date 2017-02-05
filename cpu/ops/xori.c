/* xori.c - eXclusive OR Immediate */

#include <vr4300i.h>

/*
  XORI rt, rs, immediate
  do a bitwise logical EXCLUSIVE OR with a constant.
  rd = (rs XOR immediate)
*/

#define OPCODE 0xe

void ns4_vr4300i_xori(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t immediate = (vr -> op >> 0x0) & 0xffff;

	ns4_debug("xori %s, %s, 0x%x", regstrs[rs], regstrs[rt], immediate);
}