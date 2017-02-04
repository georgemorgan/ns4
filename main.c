/*
 * NS4 - A verbose and unoptimized Nintendo 64 Emulator.
 *
 * George Morgan (george@george-morgan.com) 2017
 *
 * It is my hope to port this project to Rust (r64) someday once
 * I have a better understanding of the architecture of the N64
 * console, its hardware, and its rendering pipeline.
 */

/* Top-level project header. */
#include <ns4.h>
/* Virtual console declarations. */
#include <vc.h>

int main(int argc, char *argv[]) {
    /* Assert if too few arguments are passed to the program. */
    ns4_assert(argc > 1, NS4_ERROR, "No ROM path provided as program argument." USAGE);
    /* Create a local copy of the virtual console. */
    struct _ns4_vc vc;
    /* Instantiate the virtual console. */
    ns4_vc_create(&vc, argv[1]);
    /* Display the ROM information. */
    ns4_vc_rom_info(&vc);

    return EXIT_SUCCESS;
}

/* Called before program termination. */
void ns4_cleanup(void) {

}
