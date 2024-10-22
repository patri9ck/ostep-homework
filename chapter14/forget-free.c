/*
==23693== HEAP SUMMARY:
==23693==     in use at exit: 8 bytes in 1 blocks
==23693==   total heap usage: 1 allocs, 0 frees, 8 bytes allocated
==23693== 
==23693== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==23693==    at 0x48447A8: malloc (vg_replace_malloc.c:446)
==23693==    by 0x109151: main (in /home/patrick/Studium/ostep-homework/chapter14/a.out)
==23693== 
==23693== LEAK SUMMARY:
==23693==    definitely lost: 8 bytes in 1 blocks
==23693==    indirectly lost: 0 bytes in 0 blocks
==23693==      possibly lost: 0 bytes in 0 blocks
==23693==    still reachable: 0 bytes in 0 blocks
==23693==         suppressed: 0 bytes in 0 blocks
*/

#include <stdlib.h>

int main(int argc, char **argv) {
    int *ptr  = malloc(2 * sizeof(int));

    ptr[0] = 2;
    ptr[1] = 3;

    free(ptr);
}
