#ifndef __ns4_h__
#define __ns4_h__

/* Inlcude the standard library headers, of course. */
#include <stdarg.h>
#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A variety of XTERM color macros. */
#define KRST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define FRED(x) KRED x KRST
#define FGRN(x) KGRN x KRST
#define FYEL(x) KYEL x KRST
#define FBLU(x) KBLU x KRST
#define FMAG(x) KMAG x KRST
#define FCYN(x) KCYN x KRST
#define FWHT(x) KWHT x KRST
#define BOLD(x) "\x1B[1m" x KRST
#define UNDL(x) "\x1B[4m" x KRST

/* Usage message. */
#define USAGE KRST "\n  usage: ./ns4 <rom> [<options> ...]\n"

/* Debugging function. */
#define ns4_debug(fmt, ...) fprintf(stdout, KGRN fmt KRST, __VA_ARGS__);

/* Values of the assertions that can be passed to the assertion function. */
enum { NS4_ERROR, NS4_WARN };
/* Assertion function for easier error handling, declared as a printf-like function. */
extern void ns4_assert(bool equality, uint8_t type, const char *fmt, ...) __attribute__ ((format (printf, 3, 4)));

#endif
