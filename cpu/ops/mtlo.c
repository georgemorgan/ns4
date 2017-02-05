/* mtlo.c - Move LO register */

#include <vr4300i.h>

/*
  MTLO rs
  copy a GPR the special purpose LO register.
*/

#define OPCODE 0x0

void ns4_vr4300i_mtlo(struct _vr4300i *vr) {
	uint32_t rs = (vr -> op >> 0x15) & 0x1f;

	/* no imp */;

	ns4_debug("mtlo %s", regstrs[rs]);
}