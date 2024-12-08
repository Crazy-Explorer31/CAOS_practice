#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "read_file.h"

struct FileContent read_file(int fd) {
    struct FileContent ret = {-1L, NULL};
    size_t capacity = 0;
    size_t size = 0;
    char *p = NULL;
    char buf[4096];

    while (1) {
        ssize_t r = read(fd, buf, sizeof(buf));
        if (r < 0) {
            // ошибка
            return ?;
        }
        if (EOF) {
            // 1. не забыть: файл может быть размера 0 (touch a.txt)
            // 2. не забыть: всегда null-terminated string!
            return ?;
        }
        if (в массиве не хватает места) {
            // realloc
        }
        memcpy(p + size, buf, r);
        size += r;
    }
}
