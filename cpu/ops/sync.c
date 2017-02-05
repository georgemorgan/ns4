/* sync.c - SYNChronize shared memory */

#include <vr4300i.h>

/*
  SYNC          (stype = 0 implied)
  order loads and stores shared memory in amultiprocessor system.
*/

#define OPCODE 0x0

void ns4_vr4300i_sync(struct _vr4300i *vr) {
	uint32_t stype = (vr -> op >> 0x6) & 0x1f;

	ns4_debug("sync 0x%x", stype);
}