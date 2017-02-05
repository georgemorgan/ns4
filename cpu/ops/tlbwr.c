/* tlbwr.c - Translation Lookaside Buffer Write Random */

#include <vr4300i.h>

/*
  TLBWR
  The G bit of the TLB is written with the logical AND of the G bitsin the EntryLo0 and EntryLo1 registers. The TLB entry pointed at bythe contents of the TLB Random register is loaded with the contentsof the EntryHi and EntryLo registers.
*/

#define OPCODE 0x10

void ns4_vr4300i_tlbwr(struct _vr4300i *vr) {
	uint32_t CO = (inst() >> 0x19) & 0x1;
	uint32_t 0000 0000 0000 0000 000 = (inst() >> 0x6) & 0x7ffff;
	uint32_t 000110 (6) = (inst() >> 0x0) & 0x3f;

	ns4_debug("tlbwr CO, ");
}