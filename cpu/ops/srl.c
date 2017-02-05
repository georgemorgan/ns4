/* srl.c - Shift word Right Logical */

#include <vr4300i.h>

/*
  SRL rd, rt, sa
  logical right shift a word by a fixed number of bits.
  rd = rt >> sa
*/

#define OPCODE 0x0

void ns4_vr4300i_srl(struct _vr4300i *vr) {
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;
	uint32_t sa = (vr -> op >> 0x6) & 0x1f;

	ns4_debug("srl rt, rd, sa, ");
}