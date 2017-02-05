/* dsrl32.c - Doubleword Shift Right Logical +32 */

#include <vr4300i.h>

/*
  DSRL32 rd, rt, sa
  logical right shift a doubleword by a fixed amount-- 32 63 bits.
  rd = rt >> ( sa+32 )
*/

#define OPCODE 0x0

void ns4_vr4300i_dsrl32(struct _vr4300i *vr) {
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;
	uint32_t sa = (vr -> op >> 0x6) & 0x1f;

	vr -> regs[rd] = vr -> regs[rt] >> (sa+32);

	ns4_debug("dsrl32 %s, %s, 0x%x", regstrs[rt], regstrs[rd], sa);
}