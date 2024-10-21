#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>


int main(int argc, char **argv) {
    int n = 100;

    if (argc > 1) {
        n = strtol(argv[1], NULL, 10);
    }

    int it = 5;

    if (argc > 2) {
        it = strtol(argv[2], NULL, 10);
    }

    n = n * 1024 * 1024;

    printf("Allocating %d Bytes\n", n);

    int *buffer = malloc(n);

    if (buffer == NULL) {
        return 1;
    }

    for (int i = 0; i < it || it < 0; ++i) {
        for (int i = 0; i < n / sizeof(int); ++i) {
            buffer[i] = i;
        }
    }

    free(buffer);

    return 0;
}
