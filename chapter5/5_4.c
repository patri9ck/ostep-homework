// There could be many variants of the same call to provide maximum flexibility to the developer.
#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int main() {
    int rc = fork();

    if (rc < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (rc == 0) {
        char *args[] = {"ls", NULL};
        char *envp[] = {"USER=patrick", NULL};
        // Provide path of binary
        //execl("/bin/ls", "ls", NULL);
        
        // Provide path of binary and use envp
        execle("/bin/sh", "sh", "5_4-test.sh", NULL, envp);
        
        // Use $PATH
        //execlp("ls", "ls", NULL);
        
        // Take an array as arguments
        //execv("/bin/ls", args);
        
        // Use $PATH and take an array as arguments
	//execvp("ls", args);

        // Use $PATH, take an array as arguments and use envp
        //execvpe("ls", args, envp);
    } else {
        wait(NULL);
    }
}
