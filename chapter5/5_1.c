// The value of the variable is 100 in both the child and parent process.
// Changing the value of the variable in a process does not affect the other one as both have their own registers, address space and so on

#include <unistd.h>
#include <stdio.h>

int main() {
    int x = 100;

    int rc = fork();

    printf("Value of x: %d\n", x);

    if (rc < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (rc == 0) {
        x = 13;
        printf("Child process: %d\n", x);
    } else {
        x = 14;
        printf("Parent process: %d\n", x);
    }
}