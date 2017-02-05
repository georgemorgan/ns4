/* mtlo.c - Move LO register */

#include <vr4300i.h>

/*
  MTLO rs
  copy a GPR the special purpose LO register.
*/

#define OPCODE 0x0

void ns4_vr4300i_mtlo(struct _vr4300i *vr) {
	uint32_t rs = (inst() >> 0x15) & 0x1f;
	uint32_t 0000 0000 0000 000 = (inst() >> 0x6) & 0x7fff;
	uint32_t 010011 (19) = (inst() >> 0x0) & 0x3f;

	ns4_debug("mtlo rs, ");
}