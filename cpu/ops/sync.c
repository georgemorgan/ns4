/* sync.c - SYNChronize shared memory */

#include <vr4300i.h>

/*
  SYNC          (stype = 0 implied)
  order loads and stores shared memory in amultiprocessor system.
*/

#define OPCODE 0x0

void ns4_vr4300i_sync(struct _vr4300i *vr) {
	uint32_t 0000 0000 0000 000 = (inst() >> 0xb) & 0x7fff;
	uint32_t stype = (inst() >> 0x6) & 0x1f;
	uint32_t 001111 (15) = (inst() >> 0x0) & 0x3f;

	ns4_debug("sync stype, ");
}