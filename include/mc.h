#ifndef __mc_h__
#define __mc_h__

#include <ns4.h>
#include <pif.h>

struct _ns4_mc {
    /* A pointer to the ROM plane. */
    void *rom;
    /* A pointer to the DRAM plane. */
    void *rdram;
    /* The PIF device. */
    struct _ns4_pif pif;
};

/* Create a memory controller with a ROM pointer. */
void ns4_mc_create(struct _ns4_mc *mc, void *rom);
/* Reads a 32-bit value from the given virtal console's memory map. */
uint32_t mc_read32(struct _ns4_mc *mc, uint64_t address);

#endif
