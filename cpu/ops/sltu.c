/* sltu.c - Set on Less Than Unsigned */

#include <vr4300i.h>

/*
  SLTU rd, rs, rt
  record the result of an unsigned less-than comparison.
  if rs < rt then rd = 1 else rd = 0
*/

#define OPCODE 0x0

void ns4_vr4300i_sltu(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("sltu %s, %s, %s", regstrs[rs], regstrs[rt], regstrs[rd]);
}