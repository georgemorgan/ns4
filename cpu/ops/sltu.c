/* sltu.c - Set on Less Than Unsigned */

#include <vr4300i.h>

/*
  SLTU rd, rs, rt
  record the result of an unsigned less-than comparison.
  if rs < rt then rd = 1 else rd = 0
*/

#define OPCODE 0x0

void ns4_vr4300i_sltu(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 101011 (43) = (inst() >> 0x0) & 0x3f;

	ns4_debug("sltu rs, rt, rd, ");
}