// This will cause a segmentation fault.

/*
(gdb) run
Starting program: /home/patrick/Studium/ostep-homework/chapter14/a.out 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.archlinux.org>
Enable debuginfod for this session? (y or [n]) y
Debuginfod has been enabled.
To make this setting permanent, add 'set debuginfod enabled on' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Program received signal SIGSEGV, Segmentation fault.
0x0000555555555154 in main (agrc=1, argv=0x7fffffffe608) at null.c:9
9	   printf("The value of ptr is %d\n", *ptr);
(gdb)
*/

/*
<==18925== Invalid read of size 4
==18925==    at 0x109154: main (null.c:9)
==18925==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==18925== 
==18925== 
==18925== Process terminating with default action of signal 11 (SIGSEGV): dumping core
==18925==  Access not within mapped region at address 0x0
==18925==    at 0x109154: main (null.c:9)
*/
#include <stdio.h>

int main(int agrc, char **argv) {
    int *ptr;

    ptr = NULL;

    printf("The value of ptr is %d\n", *ptr);
}
