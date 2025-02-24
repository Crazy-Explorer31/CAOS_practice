#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buf[20] = "hello";
    int fd, i = 0;
    fd = atoi(argv[0]);
    puts("parent started:");
    while (1) {
        i++;
        sprintf(buf, "hello:%d", i);
        write(fd, buf, 10);
        sleep(2);
    }
    return 0;
}