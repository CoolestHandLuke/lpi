#include <stdio.h>
#include <gnu/libc-version.h>
#include <errno.h>
#include <string.h>


int
main() {

    char const *version_number = gnu_get_libc_version();
    puts(version_number);


    // Error handling
    // perror will print the message provided, followed by another message pertaining to whatever errno is set to.
    // Comes from <stdio.h>
    FILE *fd = fopen("non_existent_file", "r");
    if (fd == NULL) {
        perror("Failure to read file");
        
    } else {
        fclose(fd);
    }

    // strerror will print the message pertaining to its provided int argument
    // Comes from <string.h>
    FILE *fd_2 = fopen("another_bad_file", "r");
    if (fd == NULL) {
        char *err_message = strerror(errno);
        puts(err_message);
    } else {
        fclose(fd);
    }
    return 0;
}