#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>


#define TEST_CYCLES 100000000

int
my_func(int);

int
main(int argc, char **argv[]) {

    int result;
    pid_t result_ppid;
    clock_t start_time = clock();
    // 100,000,000 cycles
    // Average of 0.15 seconds
    for (int i = 0; i < TEST_CYCLES; ++i) {
        result = my_func(i);
    }
    clock_t end_time = clock();
    double delta_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Total elapsed time for user function call is: %f\n", delta_time);

    start_time = clock();
    // 100,000,000 cycles
    // Average of 13.2 seconds (!)
    for (int i = 0; i < TEST_CYCLES; ++i) {
        result_ppid = getppid();
    }
    end_time = clock();
    delta_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Total elapsed time for system call is: %f\n", delta_time);
    
    return 0;
}

int
my_func(int int_to_return) {
    return int_to_return;
}