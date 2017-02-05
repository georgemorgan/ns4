/* jr.c - Jump Register */

#include <vr4300i.h>

/*
  JR rs
  branch an instruction address in a register.
  PC = rs
*/

#define OPCODE 0x0

void ns4_vr4300i_jr(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 0000 0000 0000 000 = (inst() >> 0x6) & 0x7fff;
	uint32_t 001000 (8) = (inst() >> 0x0) & 0x3f;

	ns4_debug("jr rs, ");
}