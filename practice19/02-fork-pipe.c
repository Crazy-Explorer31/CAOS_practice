#include <stdio.h>
#include <unistd.h>

int main() {
    int arr[2];
    char argv[30];
     pipe(arr);
    // arr[0] -- read end of pipe
    // arr[1] -- write end of pipe
    // arr[1] --> arr[0]
    if (fork()) {
        char buf[20] = "hello";
        int i = 0;
        puts("parent started:");
        while (i < 4) {
            i++;
            sprintf(buf, "hello:%d", i);
            write(arr[1], buf, 10);
            sleep(2);
        }
        puts("parent ended");
    } else {
        char buf[11];
        int i = 0;
        puts("child started");
        close(arr[1]);
        while (i  < 5) {
            i++;
            read(arr[0], buf, 10);
            puts(buf);
        }
        puts("child ended");
    }

    return 1;
}
