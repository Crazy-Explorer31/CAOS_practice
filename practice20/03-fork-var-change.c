#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int x = 1;

    if (fork() == 0) {
        sleep(1);
        printf("Child: %d\n", x);
        x = 100;
    } else {
        printf("Parent: %d\n", x);
        x = 500;
        wait(NULL);
    }
    return 0;
}
