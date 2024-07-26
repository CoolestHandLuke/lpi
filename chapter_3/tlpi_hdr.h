/* Header file used by most example programs. Put together here for ease of use. */
#ifndef TLPI_HDR_H
#define TLPI_HDR_H

#include <sys/types.h>  /* Type defs used by many programs */
#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Prototypes for commonly used library functions, as well as EXIT_STATUS and EXIT_FAILURE constatns. */
#include <unistd.h>     /* Prototypes for many system calls */
#include <errno.h>      /* Declares errno and defines error constants */
#include <string.h>     /* Commonly used string-handling functions */

// #include "get_num.h"    /* Custom methods for handling numbers */
// #include "error_functions.h"     /* Declares custom error-handling functions */

typedef enum { FALSE, TRUE} Boolean;

#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) > (n) ? (m) : (n))

#endif

