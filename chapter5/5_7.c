// If the child closes STDOUT_FILENO, only the parent can print to the standard output. printf() has no effect for the child process.
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int rc = fork();

    if (rc < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (rc == 0) {
        close(STDOUT_FILENO);

        int pid = getpid();

        printf("pid of child: %d\n", pid);
    } else {
        wait(NULL);

        int pid = getpid();

        printf("pid of parent: %d\n", pid);
    }
}