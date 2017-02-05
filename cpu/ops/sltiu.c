/* sltiu.c - Set on Less Than Immediate Unsigned */

#include <vr4300i.h>

/*
  SLTIU rt, rs, immediate
  record the result of an unsigned less-thancomparison with a constant.
  if rs < immediate then rd = 1 else rd = 0
*/

#define OPCODE 0xb

void ns4_vr4300i_sltiu(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t immediate = (inst() >> 0x0) & 0xffff;

	ns4_debug("sltiu rs, rt, immediate, ");
}