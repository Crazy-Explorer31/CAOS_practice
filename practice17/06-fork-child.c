#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char buf[11];
    int fd;
    puts("child started");
    fd = atoi(argv[0]);
    while (1) {
        read(fd, buf, 10);
        puts(buf);
    }
    return 0;
}