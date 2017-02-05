/* and.c - AND */

#include <vr4300i.h>

/*
  AND rd, rs, rt
  do a bitwise logical AND.
  rd = (rs AND rt)
*/

#define OPCODE 0x0

void ns4_vr4300i_and(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("and rs, rt, rd, ");
}