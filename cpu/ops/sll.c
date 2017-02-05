/* sll.c - Shift word Left Logical */

#include <vr4300i.h>

/*
  SLL rd, rt, sa
  left shift a word by a fixed number of bits.
   Comment: SLL r0, r0, 0 is equal a NOP (No OPeration)
  rd = rt << sa
*/

#define OPCODE 0x0

void ns4_vr4300i_sll(struct _vr4300i *vr) {
	uint32_t 00000 = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t sa = (inst() >> 0x6) & 0x1f;
	uint32_t 000000 (0) = (inst() >> 0x0) & 0x3f;

	ns4_debug("sll rt, rd, sa, ");
}