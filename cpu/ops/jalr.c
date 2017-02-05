/* jalr.c - Jump And Link Register */

#include <vr4300i.h>

/*
  JALR rs, rd
  procedure call an instruction address in a register.
  return address in rd
*/

#define OPCODE 0x0

void ns4_vr4300i_jalr(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 00000 = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 001001 (9) = (inst() >> 0x0) & 0x3f;

	ns4_debug("jalr rs, rd, ");
}