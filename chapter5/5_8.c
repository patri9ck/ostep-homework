#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefds[2];
    pid_t pid1, pid2;

    if (pipe(pipefds) == -1) {
        return 1;
    }

    pid1 = fork();

    if (pid1 == -1) {
        return 1;
    }

    if (pid1 == 0) {
        close(pipefds[0]);

        dup2(pipefds[1], STDOUT_FILENO);

        close(pipefds[1]);

        printf("Hello from the first child!\n");
        fflush(stdout); 

        return 0;
    }

    pid2 = fork();

    if (pid2 == -1) {
        return 1;
    }

    if (pid2 == 0) {
        char buffer[100];

        close(pipefds[1]);

        ssize_t nbytes = read(pipefds[0], buffer, sizeof(buffer) - 1);
        
        if (nbytes > 0) {
            buffer[nbytes] = '\0';
            
            printf("Second child received: %s", buffer);
        }

        close(pipefds[0]);

        return 0;
    }

    close(pipefds[0]);
    close(pipefds[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
