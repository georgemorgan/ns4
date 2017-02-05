/* dsra.c - Doubleword Shift Right Arithmetic */

#include <vr4300i.h>

/*
  DSRA rd, rt, sa
  arithmetic right shift a doubleword by a fixedamount -- 0 31 bits.
  rd = rt >> sa
*/

#define OPCODE 0x0

void ns4_vr4300i_dsra(struct _vr4300i *vr) {
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;
	uint32_t sa = (vr -> op >> 0x6) & 0x1f;

	vr -> regs[rd] = vr -> regs[rt] >> vr -> regs[sa];

	ns4_debug("dsra %s, %s, 0x%x", regstrs[rt], regstrs[rd], sa);
}