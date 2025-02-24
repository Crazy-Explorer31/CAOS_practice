#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(void) {
    int pid, status, fd;
    fd = open("./notes.md", O_RDWR);
    pid = fork();
    if (pid > 0) {
        char buf[31];
        read(fd, buf, 30);
        buf[30] = 0;
        puts(buf);
        wait(&status);
    } else {
        char buf[31];
        //sleep(3);
        read(fd, buf, 30);
        buf[30] = 0;
        puts(buf);
        exit(0);
    }
}
