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

#define swap_le(word) (((word >> 24) & 0xff) | ((word << 8) & 0xff0000) | ((word >> 8) & 0xff00) | ((word << 24) & 0xff000000))

void ns4_mc_create(struct _ns4_mc *mc, void *rom) {
    /* Store the ROM pointer. */
    mc -> rom = rom;
    /* Allocate memory for the sytem RDRAM. */
    mc -> rdram = malloc(N64_RDRAM_SIZE);
    /* Give the virtual console a PIF. */
    pif_create(&(mc -> pif));
}

uint32_t mc_read32(struct _ns4_mc *mc, uint64_t address) {

    if (address >= 0x000000 && address < 0x3f00000) {
	    /* RDRAM Memory */

    } else if (address >= 0x3f00000 && address < 0x4000000) {
    	/* RDRAM Registers */

    } else if (address >= 0x4000000 && address < 0x4100000) {
    	/* SP Registers */

    } else if (address >= 0x4100000 && address < 0x4200000) {
    	/* DP Command Registers */

    } else if (address >= 0x4200000 && address < 0x4300000) {
    	/* DP Span Registers */

    } else if (address >= 0x4300000 && address < 0x4400000) {
    	/* MIPS Interface (MI) Registers */

    } else if (address >= 0x4400000 && address < 0x4500000) {
    	/* Video Interface (VI) Registers */

    } else if (address >= 0x4500000 && address < 0x4600000) {
    	/* Audio Interface (AI) Registers */

    } else if (address >= 0x4600000 && address < 0x4700000) {
    	/* Peripheral Interface (PI) Registers */

    } else if (address >= 0x4700000 && address < 0x4800000) {
    	/* RDRAM Interface (RI) Registers */

    } else if (address >= 0x4800000 && address < 0x4900000) {
    	/* Serial Interface (SI) Registers */

    } else if (address >= 0x4900000 && address < 0x5000000) {
    	/* Unused */

    } else if (address >= 0x5000000 && address < 0x6000000) {
    	/* Cartridge Domain 2 Address 1 */
        return swap_le(*(uint32_t *)(mc -> rom + (address - 0x5000000)));
    } else if (address >= 0x6000000 && address < 0x8000000) {
    	/* Cartridge Domain 1 Address 1 */
        return swap_le(*(uint32_t *)(mc -> rom + (address - 0x6000000)));
    } else if (address >= 0x8000000 && address < 0x10000000) {
    	/* Cartridge Domain 2 Address 2 */
        return swap_le(*(uint32_t *)(mc -> rom + (address - 0x8000000)));
    } else if (address >= 0x10000000 && address < 0x1fc00000) {
    	/* Cartridge Domain 1 Address 2 */
        return swap_le(*(uint32_t *)(mc -> rom + (address - 0x10000000)));
    } else if (address >= 0x1fc00000 && address < 0x1fc007c0) {
    	/* PIF */

    } else if (address >= 0x1fc007c0 && address < 0x1fc00800) {
    	/* PIF */

    } else if (address >= 0x1fc00800 && address < 0x1fd00000) {
    	/* Reserved */

    } else if (address >= 0x1fd00000 && address < 0x80000000) {
    	/* Cartridge Domain 1 Address 3 */
        return swap_le(*(uint32_t *)(mc -> rom + (address - 0x1fd00000)));
    } else if (address >= 0x80000000 && address < 0x100000000) {
    	/* External SysAD Device */

    } else {
    	ns4_debug("Invalid memory access at 0x%08x", address);
    }

}
