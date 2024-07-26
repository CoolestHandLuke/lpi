/* Custom error handling functions */
#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

/** Prints a message on standard error. Same as printf(), except a terminating newline is 
 * appended to the output string.
 * Also prints the error text corresponding to the current value of errno.
 * 
 */
void errMsg(const char *format, ...);

#ifdef __GNUC__

/* This macro stops 'gcc -Wall' complaining that "control reaches
    end of non-void function" if we use the following functions to
    terminate main() or some other non-void function. */
#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

/** Prints a message on standard error and then exits the program using abort() if EF_DUMPCORE is set, _exit() otherwise.
 * Similar to err_exit(), however this function flushes the standard output before printing the error message
 * and will use _exit() rather than exit().
 */
void errExit(const char *format, ...) NORETURN ;

/** Prints a message on standard error and then exits the program using abort() if EF_DUMPCORE is set, exit() otherwise.
 * Similar to errExit(), however this function does not flush the standard output before printing the error message
 * and will use exit() rather than _exit().
 */
void err_exit(const char *format, ...) NORETURN ;

/** Does the same thing as errExit(), except that instead of printing the error text of the current value of errno, 
 * it prints the text corresponding to the error number in errnum.
 * Used mainly in programs that employ the POSIX threads API.
 */
void errExitEN(int errnum, const char *format, ...) NORETURN ;

/** Used to diagnose general errors, including library functions that don't set errno. */
void fatal(const char *format, ...) NORETURN ;

/** Used to diagnose errors in command-line argument usage. */
void usageErr(const char *format, ...) NORETURN ;

/** Similar to usageError(), but is intended for diagnosing errors in the command_line arguments specified to the program. */
void cmdLineErr(const char *format, ...) NORETURN ;

#endif