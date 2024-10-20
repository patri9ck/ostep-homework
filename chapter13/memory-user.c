#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int n = 100;

    if (argc > 1) {
        n = strtol(argv[1], NULL, 10);
    }

    int it = 5;

    if (argc > 2) {
        it = strtol(argv[2], NULL, 10);
    }

    n = n * 1000000;

    char *buffer = calloc(n, 1);

    if (buffer == NULL) {
        return 1;
    }

    for (int i = 0; i < it; ++i) {
        for (int i = 0; i < n; ++i) {
            printf("Address after %d Byte: %p\n", i, buffer + i);
        }
    }

    free(buffer);

    return 0;
}
