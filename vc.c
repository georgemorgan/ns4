#include <vc.h>
#include <n64.h>

static inline void validate_vc(struct _ns4_vc *vc) {
    ns4_assert(vc, NS4_ERROR, "No virtal console provided to VC instance.");
}

void ns4_vc_create(struct _ns4_vc *vc, char *path) {
    /* Ensure the VC is valid. */
    validate_vc(vc);
    /* Load the image from the disk. */
    FILE *image = fopen(path, "rb+");
    /* Assert if the image could not be loaded. */
    ns4_assert(image, NS4_ERROR, "Failed to load ROM '%s'. (%s.)", path, strerror(errno));
    /* Obtain the image size. */
    fseek(image, 0, SEEK_END);
    size_t size = ftell(image);
    fseek(image, 0, SEEK_SET);
    /* Allocate memory for the ROM plane. */
    vc -> rom = malloc(size);
    /* Load the ROM into the virtual console. */
    fread(vc -> rom, sizeof(uint8_t), size, image);
    /* Close the image on the disk. */
    fclose(image);
    /* Allocate memory for the sytem RDRAM. */
    vc -> rdram = malloc(N64_RDRAM_SIZE);
}

void ns4_vc_rom_info(struct _ns4_vc *vc) {
    /* Ensure the VC is valid. */
    validate_vc(vc);
    /* Assert if no ROM has been loaded. */
    ns4_assert(vc -> rom, NS4_WARN, "No ROM has been loaded into the virtual console '%p'.", vc);
    /* Cast to the ROM header. */
    struct _n64_rom_header *header = (struct _n64_rom_header *)vc -> rom;
    /* Display the name. */
    ns4_debug("%s\n", header -> name);
}


void ns4_vc_destroy(struct _ns4_vc *vc) {
    /* Ensure the VC is valid. */
    validate_vc(vc);
}
