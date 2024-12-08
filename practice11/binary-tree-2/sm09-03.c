#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

struct Node {
    int key;
    int left_idx;
    int right_idx;
};

int read_node(int fd, int idx, struct Node *nd) {
    int val;
    lseek(fd, idx * sizeof(*nd), SEEK_SET);
    val = read(fd, nd, sizeof(*nd));

    return val;
}

void traverse(int fd, int idx) {
    struct Node nd;

    read_node(fd, idx, &nd);
    // А если при чтении случилась ошибка?

    Если есть элементы в левом поддереве, то обойти его
    Если есть элементы в правом поддереве, то обойти его
    А может наоборот?
        <<На стандартный поток вывода напечатайте ключи,
            размещенные в данном дереве, !в порядке убывания!.>>
}


int main(int argc, char *argv[]) {
    ...

    return 0;
}
