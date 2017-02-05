/* mflo.c - Move From LO register */

#include <vr4300i.h>

/*
  MFLO rd
  copy the special purpose LO register a GPR.
  rd = LO
*/

#define OPCODE 0x0

void ns4_vr4300i_mflo(struct _vr4300i *vr) {
	uint32_t 0000 0000 00 = (inst() >> 0x10) & 0x3ff;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t 00000 = (inst() >> 0x6) & 0x1f;
	uint32_t 010010 (18) = (inst() >> 0x0) & 0x3f;

	ns4_debug("mflo rd, ");
}