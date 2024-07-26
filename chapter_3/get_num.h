#ifndef GET_NUM_H
#define GET_NUM_H

#define GN_NONNEG       01      /* Value must be >= 0 */
#define GN_GT_0         02      /* Value must be > 0 */

                                /* By default, integers are decimal */
#define GN_ANY_BASE     0100    /* Can use any base*/
#define GN_BASE_8       0200    /* Valuse is expressed in octal */
#define GN_BASE_16      0400    /* Value is expressed in hexadecimal */

/** Utilizes strtol() to convert the given arg to a long. Performs error checking and will 
 * exit if invalid arguments are given.
 */
long getLong(const char *arg, int flags, const char *name);

/** Utilizes strtol() to convert the given arg to an int. Performs error checking and will 
 * exit if invalid arguments are given.
 */
int getInt(const char *arg, int falgs, const char *name);

#endif