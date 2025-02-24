#include <stdio.h>
#include <unistd.h>

int main() {
    int arr[2];
    char argv[30];
    pipe(arr);
    if (fork()) {
        puts("starting parent");
        close(arr[0]);
        sprintf(argv, "%d", arr[1]);
        execlp("./06-fork-parent.elf", argv, NULL);
    } else {
        puts("starting child");
        close(arr[1]);
        sprintf(argv, "%d", arr[0]);
        execlp("./06-fork-child.elf", argv, NULL);
    }
    return 1;
}