// wait() returns the PID of the child if successful or -1 if unsuccessful.
// Running wait() in the child process therefore returns -1 and does not block.
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

        int rc_wait = wait(NULL);

        printf("rc_wait in child: %d\n", rc_wait);
    } else {
        int rc_wait = wait(NULL);

        printf("rc_wait in parent: %d\n", rc_wait);
    }
}