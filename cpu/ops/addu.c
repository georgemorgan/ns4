/* addu.c - ADD Unsigned word */

#include <vr4300i.h>

/*
  ADDU rd, rs, rt
  add 32-bit integers.
  rd = rs + rt
*/

#define OPCODE 0x0

void ns4_vr4300i_addu(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 100001 (33) = (inst() >> 0x0) & 0x3f;

	ns4_debug("addu rs, rt, rd, ");
}