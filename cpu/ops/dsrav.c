/* dsrav.c - Doubleword Shift Right Arithmetic Variable */

#include <vr4300i.h>

/*
  DSRAV rd, rt, rs
  arithmetic right shift a doubleword by a variablenumber of bits.
  rd = rt >> rs
*/

#define OPCODE 0x0

void ns4_vr4300i_dsrav(struct _vr4300i *vr) {
	uint32_t 00000 = (inst() >> 0x15) & 0x1f;
	uint32_t rt = (inst() >> 0x10) & 0x1f;
	uint32_t rd = (inst() >> 0xb) & 0x1f;
	uint32_t rs = (inst() >> 0x6) & 0x1f;
	uint32_t 010111 (23) = (inst() >> 0x0) & 0x3f;

	ns4_debug("dsrav rt, rd, rs, ");
}