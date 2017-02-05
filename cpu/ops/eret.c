/* eret.c - Return from Exception */

#include <vr4300i.h>

/*
  ERET
  ERET is the R4300 instruction for returning from an interrupt,exception, or error trap. Unlike a branch or jump instruction,ERET does not execute the next instruction.
*/

#define OPCODE 0x10

void ns4_vr4300i_eret(struct _vr4300i *vr) {
	uint32_t CO = (vr -> op >> 0x19) & 0x1;

	ns4_debug("eret CO, ");
}