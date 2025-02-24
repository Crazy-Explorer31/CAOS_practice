#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int x, wstatus;
    puts("parent only");

    x = fork();
    if (x > 0) {
        printf("parent: do half task \n");
        wait(&wstatus);
        // if (WIFEXITED(wstatus)) {
        //     printf("exited, status=%d\n", WEXITSTATUS(wstatus));
        // } else if (WIFSIGNALED(wstatus)) {
        //    printf("killed by signal %d\n", WTERMSIG(wstatus));
        // }

    } else {
        printf("child: do half task \n");
        int ret = 0; // half task result
        exit(ret);
    }
    puts("parent only");

    return 0;
}