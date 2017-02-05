/* vc.c - Implementation of the Virtual Console datatype. */

#include <vc.h>
#include <n64.h>

static inline void validate_vc(struct _ns4_vc *vc) {
    ns4_assert(vc, NS4_ERROR, "No virtal console provided to VC instance.");
}

void ns4_vc_create(struct _ns4_vc *vc, char *path) {
    /* Ensure the VC is valid. */
    validate_vc(vc);
    /* Load the image from the disk. */
    FILE *image = fopen(path, "rb");
    /* Assert if the image could not be loaded. */
    ns4_assert(image, NS4_ERROR, "Failed to load ROM '%s'. (%s.)", path, strerror(errno));
    /* Obtain the image size. */
    fseek(image, 0L, SEEK_END);
    size_t size = ftell(image);
    fseek(image, 0L, SEEK_SET);
    /* Allocate memory for the ROM plane. */
    void *rom = malloc(size);
    /* Assert if memory allocation failed. */
    ns4_assert(rom, NS4_ERROR, "Failed to allocate memory to hold ROM.");
    /* Load the ROM into the virtual console. */
    fread(rom, sizeof(uint8_t), size, image);
    /* Close the image on the disk. */
    fclose(image);
    /* Give the console a memory controller. */
    ns4_mc_create(&(vc -> mc), rom);
    /* Give the virtual console a CPU. */
    vr4300i_create(&(vc -> cpu), &(vc -> mc));
    /* Cast to the ROM header. */
    struct _n64_rom_header *header = (struct _n64_rom_header *)vc -> mc.rom;
    /* Set the program counter equal to the entry point address of the ROM. */
    vc -> cpu.pc = 0x06000040; //header -> pc;
}

void ns4_vc_rom_info(struct _ns4_vc *vc) {
    /* Ensure the VC is valid. */
    validate_vc(vc);
    /* Assert if no ROM has been loaded. */
    ns4_assert(vc -> mc.rom, NS4_WARN, "No ROM has been loaded into the virtual console '%p'.", vc);
    /* Cast to the ROM header. */
    struct _n64_rom_header *header = (struct _n64_rom_header *)vc -> mc.rom;
    /* Display the name. */
    ns4_debug("%s\n", header -> name);
}


void ns4_vc_destroy(struct _ns4_vc *vc) {
    /* Ensure the VC is valid. */
    validate_vc(vc);
}
