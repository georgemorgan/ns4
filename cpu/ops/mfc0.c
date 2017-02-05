/* mfc0.c - Move word From CP0 */

#include <vr4300i.h>

/*
  MFC0 rt, rd
  copy a word from an FPR a GPR.
  rt = COP rd
*/

#define OPCODE 0x10

void ns4_vr4300i_mfc0(struct _vr4300i *vr) {
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t fs = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("mfc0 rt, fs, ");
}