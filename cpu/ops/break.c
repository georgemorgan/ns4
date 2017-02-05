/* break.c - BREAKpoint */

#include <vr4300i.h>

/*
  BREAK offset
  cause a Breakpoint exception.
*/

#define OPCODE 0x0

void ns4_vr4300i_break(struct _vr4300i *vr) {
	uint32_t code = (vr -> op >> 0x6) & 0xfffff;

	/* no imp */;

	ns4_debug("break 0x%x", code);
}