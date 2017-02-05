/* srl.c - Shift word Right Logical */

#include <vr4300i.h>

/*
  SRL rd, rt, sa
  logical right shift a word by a fixed number of bits.
  rd = rt >> sa
*/

#define OPCODE 0x0

void ns4_vr4300i_srl(struct _vr4300i *vr) {
	uint32_t 00000 = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t sa = (inst() >> 0x6) & 0x1f;
	uint32_t 000010 (2) = (inst() >> 0x0) & 0x3f;

	ns4_debug("srl rt, rd, sa, ");
}