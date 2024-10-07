// It is possible without wait() using signals (SIGCONT) along with pause().
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>


void sig_handler(int signum) {
    printf("goodbye\n");
}

int main() {
    int pid = getpid();

    int rc = fork();

    if (rc < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (rc == 0) {
        printf("hello\n");
        kill(pid, SIGCONT); // Continue
    } else {
        signal(SIGCONT, sig_handler);
        pause();
        printf("goodbye\n");
    }
}