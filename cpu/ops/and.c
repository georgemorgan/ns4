/* and.c - AND */

#include <vr4300i.h>

/*
  AND rd, rs, rt
  do a bitwise logical AND.
  rd = (rs AND rt)
*/

#define OPCODE 0x0

void ns4_vr4300i_and(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 100100 (36) = (inst() >> 0x0) & 0x3f;

	ns4_debug("and rs, rt, rd, ");
}