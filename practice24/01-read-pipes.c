#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_RDONLY);

    char buf[BUFFER_SIZE];

    while (1) {
        ssize_t size1 = read(fd1, buf, BUFFER_SIZE);
        if (size1 > 0) {
            printf("[CH1]: %.*s", (int)size1, buf);
        }

        ssize_t size2 = read(fd2, buf, BUFFER_SIZE);
        if (size2 > 0) {
            printf("[CH2]: %.*s", (int)size2, buf);
        }

        if (!size1 && !size2) break;

    }

    close(fd1);
    close(fd2);

    return 0;
}

