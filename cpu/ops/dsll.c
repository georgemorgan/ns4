/* dsll.c - Doubleword Shift Left Logical */

#include <vr4300i.h>

/*
  DSLL rd, rt, sa
  left shift a doubleword by a fixed amount -- 0 31 bits.
  rd = rt << sa
*/

#define OPCODE 0x0

void ns4_vr4300i_dsll(struct _vr4300i *vr) {
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;
	uint32_t sa = (vr -> op >> 0x6) & 0x1f;

	ns4_debug("dsll %s, %s, 0x%x", regstrs[rt], regstrs[rd], sa);
}