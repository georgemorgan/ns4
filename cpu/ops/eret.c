/* eret.c - Return from Exception */

#include <vr4300i.h>

/*
  ERET
  ERET is the R4300 instruction for returning from an interrupt,exception, or error trap. Unlike a branch or jump instruction,ERET does not execute the next instruction.
*/

#define OPCODE 0x10

void ns4_vr4300i_eret(struct _vr4300i *vr) {
	uint32_t CO = (inst() >> 0x19) & 0x1;
	uint32_t 0000 0000 0000 0000 000 = (inst() >> 0x6) & 0x7ffff;
	uint32_t 011000 (24) = (inst() >> 0x0) & 0x3f;

	ns4_debug("eret CO, ");
}