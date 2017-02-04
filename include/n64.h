/* n64.h - General Nintendo 64 Architectural and Organizational Declarations. */

#ifndef __n64_h__
#define __n64_h__

/* 4MB of external Rambus RDRAM. */
#define N64_RDRAM_SIZE 4*1024*1024

/* 64-bit MIPS CPU declarations. */
#include <vr4300i.h>

/* The structure of the N64 cartridge header. */
struct _n64_rom_header {
    uint32_t PI_BSD_DOM1;
    uint32_t clock;
    uint32_t pc;
    uint32_t release;
    uint32_t crc1;
    uint32_t crc2;
    uint64_t unknown1;
    char name[20];
    uint32_t unknown2;
    uint32_t format;
    uint16_t id;
    uint8_t country;
    uint8_t version;
};

#endif
