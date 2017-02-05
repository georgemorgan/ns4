/* xor.c - eXclusive OR */

#include <vr4300i.h>

/*
  XOR rd, rs, rt
  do a bitwise logical EXCLUSIVE OR.
  rd = (rs XOR rt)
*/

#define OPCODE 0x0

void ns4_vr4300i_xor(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("xor %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}