#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

clock_t getTime(void);

/**
 * Determine how long it would take to iterate 1 million elements in array
 */
int main (int argc, char **argv) {
    // Get start time of execution
    clock_t start, end;
    double cpu_time_used;
    start = getTime();
    // Get an input number form the command line
    int u = atoi(argv[1]);
    // Get a random integer 0 <= r < 10k
    int r = rand() % 1000;
    // Array of 10k elements initialized to 0
    int32_t a[10000] = {0};
    // 10k outer loop iteration
    for (int i = 0; i < 10000; i++) {
        // 100k inner loop iterations, per outer loop iteration
        for (int j = 0; j < 100000; j++) {
            // Simple sum
            a[i] = a[i] + u;
        }
        // Add a random value to each element in array
        a[i] += r;
    }
    // Print a single element from the array
    printf("%d\n", a[r]);

    // Get end time of execution
    end = getTime();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime took to execute: %f seconds\n", cpu_time_used);
    return 0;
}

clock_t getTime(void) {
    return clock();
}
