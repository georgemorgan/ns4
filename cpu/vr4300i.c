/* vr4300i.c - Top-level implementation of the CPU emulator. */

#include <ns4.h>
#include <vr4300i.h>
#include <mc.h>

/* Register strings for debugging purposes. */
const char *regstrs[] = { "r0", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "s8", "ra" };

void vr4300i_create(struct _vr4300i *vr, struct _ns4_mc *mc) {
    /* Set the CPU's memory controller. */
    vr -> mc = mc;
    /* Set the register address. */
    vr -> regs = &(vr -> r0);
}

void vr4300i_step(struct _vr4300i *vr) {
    /* Print the program counter. */
    ns4_debug("0x%08x: ", vr -> pc);
    /* Load the next instruction from memory. */
    vr -> op = mc_read32(vr -> mc, vr -> pc);
    /* Exeucte the instruction. */
    vr4300i_exec(vr);
    /* Increment the program counter by the width of a single instruction. */
    vr -> pc += sizeof(uint32_t);
}
