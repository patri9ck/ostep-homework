/*
==29782== Invalid write of size 4
==29782==    at 0x109160: main (in /home/patrick/Studium/ostep-homework/chapter14/a.out)
==29782==  Address 0x4a651d0 is 224 bytes inside an unallocated block of size 4,194,032 in arena "client"
*/

#include <stdlib.h>

int main(int argc, char **argv) {
    // 100 / sizeof(int) integers will fit (25)
    int *data = malloc(100);
    
    // Biggest index is actually 24
    data[100] = 0;

}
