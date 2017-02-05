/* dsubu.c - Doubleword SUBtract Unsigned */

#include <vr4300i.h>

/*
  DSUBU rd, rs, rt
  subtract 64-bit integers.
  rd = rs - rt
*/

#define OPCODE 0x0

void ns4_vr4300i_dsubu(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("dsubu %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}