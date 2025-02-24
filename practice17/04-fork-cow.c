#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static __inline__ unsigned long long rdtsc(void) {
    unsigned hi, lo;
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)lo) | (((unsigned long long)hi) << 32);
}

int arr[10000000] = {0};

void main(void) {
    int pid, status;
    long long t1, t2, t3, t4;
    pid = fork();
    if (pid > 0) {
        t1 = rdtsc();
        arr[10000] = 20;
        t2 = rdtsc();
        arr[20000] = 30;
        t3 = rdtsc();
        arr[30000] = 40;
        t4 = rdtsc();

        printf("t2 - t1 = %lld\n", t2 - t1);
        printf("t3 - t2 = %lld\n", t3 - t2);
        printf("t4 - t3 = %lld\n", t4 - t3);
        wait(&status);
    } else {
        printf("child \n");
        exit(0);
    }
    puts("parent only");
}
