// Using waitpid(), the PID of the process to wait for can be specified.
// A PID of -1 means to wait for any child processes.
// waitpid() can be useful if there are multiple children but the parent should only wait for one specific child.
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int rc = fork();

    if (rc < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (rc == 0) {
        int pid = getpid();

        printf("pid of child: %d\n", pid);
    } else {
        waitpid(-1, NULL, 0);

        int pid = getpid();

        printf("pid of parent: %d\n", pid);
    }
}