/* vc.h - Nintendo 64 VC (Virtual Console) Definitions */

#ifndef __vc_h__
#define __vc_h__

#include <ns4.h>
#include <vr4300i.h>
#include <mc.h>

/* The virtual console structure. */
struct _ns4_vc {
    /* The console's memory controller. */
    struct _ns4_mc mc;
    /* The console's VR4300i 64-bit MIPS CPU. */
    struct _vr4300i cpu;
};

/* Creates a new virtual console given a path to the ROM image. */
void ns4_vc_create(struct _ns4_vc *vc, char *path);
/* Displays information about the loaded ROM. */
void ns4_vc_rom_info(struct _ns4_vc *vc);
/* Shuts down emulation and releases the virtual console. */
void ns4_vc_destroy(struct _ns4_vc *vc);

#endif
