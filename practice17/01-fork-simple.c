#include <stdio.h>
#include <unistd.h>

int main(void) {
    puts("hello");
    fork();
    puts("bye");
    return 0;
}