/* vr4300i.c - Top-level implementation of the CPU emulator. */

#include <ns4.h>
#include <vr4300i.h>
#include <mc.h>

void vr4300i_create(struct _vr4300i *vr, struct _ns4_mc *mc) {
    /* Set the CPU's memory controller. */
    vr -> mc = mc;
}

void vr4300i_step(struct _vr4300i *vr) {
    ns4_debug("PC: 0x%08x:\n\t", vr -> pc);
    /* Load the next instruction from memory. */
    vr -> op = mc_read32(vr -> mc, vr -> pc);
    ns4_debug("OP: 0x%08x:\n\t", vr -> op);
    /* Exeucte the instruction. */
    vr4300i_exec(vr);
    /* Increment the program counter by the width of a single instruction. */
    vr -> pc += sizeof(uint32_t);
}
