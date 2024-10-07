// Both the parent and the child process can access the file descriptor.
// When both process write at the file concurrently, the parent process seems to write always first. Although this is not determinstic in which order the processes write.
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("5_2-out.txt", O_CREAT | O_WRONLY, 0644);

    if (fd < 0) {
        printf("Cannot open file\n");
        return 1;
    }

    int rc = fork();

    if (rc < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (rc == 0) {
        char *msg = "hello";
        write(fd, msg, strlen(msg));
    } else {
        char *msg = "goodbye";
        write(fd, msg, strlen(msg));
    }
}