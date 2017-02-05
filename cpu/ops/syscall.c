/* syscall.c - SYStem CALL */

#include <vr4300i.h>

/*
  SYSCALL offset
  cause a System Call exception.
*/

#define OPCODE 0x0

void ns4_vr4300i_syscall(struct _vr4300i *vr) {
	uint32_t code = (vr -> op >> 0x6) & 0xfffff;

	ns4_debug("syscall 0x%x", code);
}