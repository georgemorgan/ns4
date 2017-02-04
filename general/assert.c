#include <ns4.h>

/* Assertion function for better error handling. */
void ns4_assert(bool equality, uint8_t type, const char *fmt, ...) {
    if (!equality) {
        va_list args;
        va_start(args, fmt);
        switch (type) {
            case NS4_ERROR:
                fprintf(stderr, KRED "ERROR: ");
                vfprintf(stderr, fmt, args);
                fprintf(stderr, KRST);
                exit(EXIT_FAILURE);
            break;
            case NS4_WARN:
                fprintf(stdout, KYEL "WARNING: ");
                vfprintf(stdout, fmt, args);
                fprintf(stdout, KRST);
            break;
        }
    }
}
