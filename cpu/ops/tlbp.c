/* tlbp.c - Translation Lookaside Buffer Probe */

#include <vr4300i.h>

/*
  TLBP
  The Index register is loaded with the address of the TLB entrywhose contents match the contents of the EntryHi register. If noTLB entry matches, the high-order bit of the Index register is set.The architecture does not specify the operation of memory referencesassociated with the instruction immediately after a TLBP instruction,nor is the operation specified if more than one TLB entry matches.
*/

#define OPCODE 0x10

void ns4_vr4300i_tlbp(struct _vr4300i *vr) {
	uint32_t CO = (inst() >> 0x19) & 0x1;
	uint32_t 0000 0000 0000 0000 000 = (inst() >> 0x6) & 0x7ffff;
	uint32_t 001000 (8) = (inst() >> 0x0) & 0x3f;

	ns4_debug("tlbp CO, ");
}