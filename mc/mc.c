/* mc.c - Memory Interface */

#include <mc.h>
#include <n64.h>
#include <pif.h>

/*
    0x0000 0000 to 0x03EF FFFF RDRAM Memory
    0x03F0 0000 to 0x03FF FFFF RDRAM Registers
    0x0400 0000 to 0x040F FFFF SP Registers
    0x0410 0000 to 0x041F FFFF DP Command Registers
    0x0420 0000 to 0x042F FFFF DP Span Registers
    0x0430 0000 to 0x043F FFFF MIPS Interface (MI) Registers
    0x0440 0000 to 0x044F FFFF Video Interface (VI) Registers
    0x0450 0000 to 0x045F FFFF Audio Interface (AI) Registers
    0x0460 0000 to 0x046F FFFF Peripheral Interface (PI) Registers
    0x0470 0000 to 0x047F FFFF RDRAM Interface (RI) Registers
    0x0480 0000 to 0x048F FFFF Serial Interface (SI) Registers
    0x0490 0000 to 0x04FF FFFF Unused
    0x0500 0000 to 0x05FF FFFF Cartridge Domain 2 Address 1
    0x0600 0000 to 0x07FF FFFF Cartridge Domain 1 Address 1
    0x0800 0000 to 0x0FFF FFFF Cartridge Domain 2 Address 2
    0x1000 0000 to 0x1FBF FFFF Cartridge Domain 1 Address 2
    0x1FC0 0000 to 0x1FC0 07BF PIF Boot ROM
    0x1FC0 07C0 to 0x1FC0 07FF PIF RAM
    0x1FC0 0800 to 0x1FCF FFFF Reserved
    0x1FD0 0000 to 0x7FFF FFFF Cartridge Domain 1 Address 3
    0x8000 0000 to 0xFFFF FFFF External SysAD Device
*/

void ns4_mc_create(struct _ns4_mc *mc, void *rom) {
    /* Store the ROM pointer. */
    mc -> rom = rom;
    /* Allocate memory for the sytem RDRAM. */
    mc -> rdram = malloc(N64_RDRAM_SIZE);
    /* Give the virtual console a PIF. */
    pif_create(&(mc -> pif));
}

uint32_t mc_read32(struct _ns4_mc *mc, uint64_t address) {

    /* Cartridge Domain 1 Address 1 */
    if (address > 0x05FFFFFF && address < 0x08000000) {
        uint32_t word = *(uint32_t *)(mc -> rom + (address - 0x06000000));
        /* Return the byte swapped word. */
        return ((word >> 24) & 0xff) | ((word << 8) & 0xff0000) | ((word >> 8) & 0xff00) | ((word << 24) & 0xff000000);
    } else {
        /* Invalid access. */
        ns4_assert(0, NS4_WARN, "Invalid access to address 0x%08x.\n", address);
    }

    return 0;
}
