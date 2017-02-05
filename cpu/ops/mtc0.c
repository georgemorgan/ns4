/* mtc0.c - Move word CP0 */

#include <vr4300i.h>

/*
  MTC0 rt, rd
  copy a word from a GPR an FPR.
  COP rd = rt
*/

#define OPCODE 0x10

void ns4_vr4300i_mtc0(struct _vr4300i *vr) {
	uint32_t 00100 (4) = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t fs = (inst() >> 0xb) & 0x1f;
	uint32_t 0000 0000 000 = (inst() >> 0x0) & 0x7ff;

	ns4_debug("mtc0 rt, fs, ");
}