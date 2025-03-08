#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Hello");
    if (!fork()) {
        _exit(0);
        //exit(0);
    }
    return 0;
}
