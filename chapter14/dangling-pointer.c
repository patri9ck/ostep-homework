// When freed before accessing it, "random" values will be printed.

/*
0: 1474395584
1: 5
2: -821586079
3: -665566227
4: 4
5: 5
6: 6
7: 7
8: 8
9: 9
*/

/*
==42428== Invalid read of size 4
==42428==    at 0x1091DB: main (in /home/patrick/Studium/ostep-homework/chapter14/a.out)
==42428==  Address 0x4a65040 is 0 bytes inside a block of size 40 free'd
==42428==    at 0x48478EF: free (vg_replace_malloc.c:989)
==42428==    by 0x1091BD: main (in /home/patrick/Studium/ostep-homework/chapter14/a.out)
==42428==  Block was alloc'd at
==42428==    at 0x48447A8: malloc (vg_replace_malloc.c:446)
==42428==    by 0x10917F: main (in /home/patrick/Studium/ostep-homework/chapter14/a.out)
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int n = 10;

    int *data = malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        data[i] = i;
    }

    free(data);

    for (int i = 0; i < n; ++i) {
        printf("%d: %d\n", i, data[i]);
    }
}
