/* break.c - BREAKpoint */

#include <vr4300i.h>

/*
  BREAK offset
  cause a Breakpoint exception.
*/

#define OPCODE 0x0

void ns4_vr4300i_break(struct _vr4300i *vr) {
	uint32_t code = (inst() >> 0x6) & 0xfffff;
	uint32_t 001101 (13) = (inst() >> 0x0) & 0x3f;

	ns4_debug("break code, ");
}