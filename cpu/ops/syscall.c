/* syscall.c - SYStem CALL */

#include <vr4300i.h>

/*
  SYSCALL offset
  cause a System Call exception.
*/

#define OPCODE 0x0

void ns4_vr4300i_syscall(struct _vr4300i *vr) {
	uint32_t code = (inst() >> 0x6) & 0xfffff;
	uint32_t 001100 (12) = (inst() >> 0x0) & 0x3f;

	ns4_debug("syscall code, ");
}