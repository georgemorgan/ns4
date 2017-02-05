/* mthi.c - Move HI register */

#include <vr4300i.h>

/*
  MTHI rs
  copy a GPR the special purpose HI register.
*/

#define OPCODE 0x0

void ns4_vr4300i_mthi(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 0000 0000 0000 000 = (inst() >> 0x6) & 0x7fff;
	uint32_t 010001 (17) = (inst() >> 0x0) & 0x3f;

	ns4_debug("mthi rs, ");
}