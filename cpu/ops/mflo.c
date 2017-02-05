/* mflo.c - Move From LO register */

#include <vr4300i.h>

/*
  MFLO rd
  copy the special purpose LO register a GPR.
  rd = LO
*/

#define OPCODE 0x0

void ns4_vr4300i_mflo(struct _vr4300i *vr) {
	uint32_t rd = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("mflo %s", regstrs[rd]);
}