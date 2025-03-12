#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


#define BUF_SIZE 200

static void handler(int sig)
{
    static const char msg[] = "\n Timer expired \n";
    write(0, msg, sizeof(msg) - 1);
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    char buf[BUF_SIZE];
    ssize_t num_read;
    int saved_errno;

    sa.sa_flags = (argc > 2) ? SA_RESTART : 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handler;
    if (sigaction(SIGALRM, &sa, NULL) == -1)
        return -1;

    // Еще есть settimer (более точный)
    alarm((argc > 1) ? atoi(argv[1]) : 10);

    num_read = read(STDIN_FILENO, buf, BUF_SIZE);

    saved_errno = errno;
    // Ensure timer is turned off
    alarm(0);
    errno = saved_errno;

    if (num_read == -1) {
        if (errno == EINTR)
            printf("Read timed out\n.");
        else
            printf("Error\n.");
    } else {
        printf("Successful read (%ld bytes).\n", (long) num_read);
    }

    return 0;
}
