#include <stdarg.h>         /* For variable assignment (va) lists*/
#include "error_functions.h"
#include "tlpi_hdr.h"
#include "ename.c.inc"      /* Defines ename and MAX_ENAME */

#ifdef __GNUC__
__attribute__ ((__noreturn__))
#endif

static void
terminate(Boolean useExit3) {

    char *s;

    /* Dump core if EF_DUMPCORE environment variable is defined and
    is a nonempty string; otherwise call exit(3) or _exit(2),
    depending on the value of 'useExit3'. */

    s = getenv("EF_DUMPCORE");  // EF_DUMPCORE is a lpi thing, not a C thing. I think.

    if (s != NULL && *s != '\0') {
        abort();                // Raises the SIGABRT signal to terminate/exit from a program. Indicates abnormal termination.
    } else if (useExit3) {
        exit(EXIT_FAILURE);     // Raises the SIGCHLD signal and terminates. 
    } else {
        _exit(EXIT_FAILURE);    // Same as exit but is the system call version.
    }
}

static void
outputError(Boolean useErr, int err, Boolean flushStdout, const char *format, va_list ap) {

}
/** Prints a message on standard error. Same as printf(), except a terminating newline is 
 * appended to the output string.
 * Also prints the error text corresponding to the current value of errno.
 * 
 */
void
errMsg(const char *format) {

}
/** Prints a message on standard error and then exits the program using exit(), or abort() if EF_DUMPCORE is set.
 * Similar to err_exit(), however this function flushes the standard output before printing the error message
 * and does not automatically terminate using _exit().
 */
void
errExit(const char *format) {

}

void
errExitEN(int errnum, const char *format, ...) {

}

void
fatal(const char *format, ...) {

}

void
usageErr(const char *format, ...) {

}

void
cmdLineErr(const char *format, ...) {

}