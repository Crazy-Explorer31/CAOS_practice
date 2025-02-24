#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(void) {
    int pid, status;
    int arr[100000] = {1, 2, 3};
    pid = fork();
    if (pid > 0) {
        arr[1] = 200;
        wait(&status);
    } else {
        sleep(3);
        printf("child: arr[1]=%d \n", arr[1]);
        exit(0);
    }
}
