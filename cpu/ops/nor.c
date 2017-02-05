/* nor.c - Not OR */

#include <vr4300i.h>

/*
  NOR rd, rs, rt
  do a bitwise logical NOT OR.
  rd = (rs NOR rt)
*/

#define OPCODE 0x0

void ns4_vr4300i_nor(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("nor rs, rt, rd, ");
}