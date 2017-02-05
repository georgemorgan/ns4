/* sll.c - Shift word Left Logical */

#include <vr4300i.h>

/*
  SLL rd, rt, sa
  left shift a word by a fixed number of bits.
   Comment: SLL r0, r0, 0 is equal a NOP ( No OPeration )
  rd = rt << sa
*/

#define OPCODE 0x0

void ns4_vr4300i_sll(struct _vr4300i *vr) {
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;
	uint32_t sa = (vr -> op >> 0x6) & 0x1f;

	vr -> regs[rd] = vr -> regs[rt] << vr -> regs[sa];

	ns4_debug("sll %s, %s, 0x%x", regstrs[rt], regstrs[rd], sa);
}