/* mthi.c - Move HI register */

#include <vr4300i.h>

/*
  MTHI rs
  copy a GPR the special purpose HI register.
*/

#define OPCODE 0x0

void ns4_vr4300i_mthi(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;

	ns4_debug("mthi %s", regstrs[rs]);
}