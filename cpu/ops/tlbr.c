/* tlbr.c - Translation Lookaside Buffer Read */

#include <vr4300i.h>

/*
  TLBR
  The G bit ( which controls ASID matching ) read from the TLB iswritten inboth of the EntryLo0 and EntryLo1 registers.The EntryHi and EntryLo registers are loaded with the contents ofthe TLB entry pointed at by the contents of the TLB Index register.The operation is invalid ( and the results are unspecified ) if thecontents of the TLB Index register are greater than the number ofTLB entries in the processor.
*/

#define OPCODE 0x10

void ns4_vr4300i_tlbr(struct _vr4300i *vr) {
	uint32_t CO = (vr -> op >> 0x19) & 0x1;

	/* no imp */;

	ns4_debug("tlbr 0x%x", CO);
}