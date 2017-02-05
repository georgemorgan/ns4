/* or.c - OR */

#include <vr4300i.h>

/*
  OR rd, rs, rt
  do a bitwise logical OR.
  rd = (rs OR rt)
*/

#define OPCODE 0x0

void ns4_vr4300i_or(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 100101 (37) = (inst() >> 0x0) & 0x3f;

	ns4_debug("or rs, rt, rd, ");
}