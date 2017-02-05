/* jr.c - Jump Register */

#include <vr4300i.h>

/*
  JR rs
  branch an instruction address in a register.
  PC = rs
*/

#define OPCODE 0x0

void ns4_vr4300i_jr(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;

	PC = vr -> regs[rs];

	ns4_debug("jr %s", regstrs[rs]);
}