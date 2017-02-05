/* mfhi.c - Move From HI register */

#include <vr4300i.h>

/*
  MFHI rd
  copy the special purpose HI register a GPR.
  rd = HI
*/

#define OPCODE 0x0

void ns4_vr4300i_mfhi(struct _vr4300i *vr) {
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("mfhi %s", regstrs[rd]);
}