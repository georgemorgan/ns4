/* nor.c - Not OR */

#include <vr4300i.h>

/*
  NOR rd, rs, rt
  do a bitwise logical NOT OR.
  rd = (rs NOR rt)
*/

#define OPCODE 0x0

void ns4_vr4300i_nor(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 100111 (39) = (inst() >> 0x0) & 0x3f;

	ns4_debug("nor rs, rt, rd, ");
}