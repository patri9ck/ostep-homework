// Valgrind reports an invalid free and a memory leak.

/*
==47360== Invalid free() / delete / delete[] / realloc()
==47360==    at 0x48478EF: free (vg_replace_malloc.c:989)
==47360==    by 0x109205: main (invalid-free.c:17)
==47360==  Address 0x4a65048 is 8 bytes inside a block of size 40 alloc'd
==47360==    at 0x48447A8: malloc (vg_replace_malloc.c:446)
==47360==    by 0x10917F: main (invalid-free.c:7)
==47360== 
==47360== 
==47360== HEAP SUMMARY:
==47360==     in use at exit: 40 bytes in 1 blocks
==47360==   total heap usage: 2 allocs, 2 frees, 1,064 bytes allocated
==47360== 
==47360== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==47360==    at 0x48447A8: malloc (vg_replace_malloc.c:446)
==47360==    by 0x10917F: main (invalid-free.c:7)
==47360== 
==47360== LEAK SUMMARY:
==47360==    definitely lost: 40 bytes in 1 blocks
==47360==    indirectly lost: 0 bytes in 0 blocks
==47360==      possibly lost: 0 bytes in 0 blocks
==47360==    still reachable: 0 bytes in 0 blocks
==47360==         suppressed: 0 bytes in 0 blocks
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int n = 10;

    int *data = malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        data[i] = i;
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%d: %d\n", i, data[i]);
    }
    
    free(data + 2);
}
