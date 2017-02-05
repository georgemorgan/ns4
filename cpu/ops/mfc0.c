/* mfc0.c - Move word From CP0 */

#include <vr4300i.h>

/*
  MFC0 rt, rd
  copy a word from an FPR a GPR.
  rt = COP rd
*/

#define OPCODE 0x10

void ns4_vr4300i_mfc0(struct _vr4300i *vr) {
	uint32_t 00000 (0) = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t fs = (inst() >> 0xb) & 0x1f;
	uint32_t 0000 0000 000 = (inst() >> 0x0) & 0x7ff;

	ns4_debug("mfc0 rt, fs, ");
}