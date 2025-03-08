#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pfd[2];  // массив для файловых дескрипторов канала
    pipe(pfd);
    pid_t pid1 = fork();
    if (!pid1) {
        dup2(pfd[1], 1);
        close(pfd[0]); close(pfd[1]);
        execlp("ls", "ls", "-l", NULL);
        _exit(1);
    }
    close(pfd[1]);
    pid_t pid2 = fork();
    if (!pid2) {
        dup2(pfd[0], 0);
        close(pfd[0]);
        execlp("wc", "wc", "-l", NULL);
        _exit(1);
    }
    close(pfd[0]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
