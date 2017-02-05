/* mtc0.c - Move word CP0 */

#include <vr4300i.h>

/*
  MTC0 rt, rd
  copy a word from a GPR an FPR.
  COP rd = rt
*/

#define OPCODE 0x10

void ns4_vr4300i_mtc0(struct _vr4300i *vr) {
	uint32_t rt = (vr -> op >> 0x10) & 0x1f;
	uint32_t fs = (vr -> op >> 0xb) & 0x1f;

	ns4_debug("mtc0 rt, fs, ");
}