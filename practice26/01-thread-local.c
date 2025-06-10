#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define N 5

_Thread_local int val = 1;
//int val = 1;

void* thread_func(void* args) {
    int i = (int)(intptr_t)(args);
    printf("%d:\t%p, %d\n", i, &val, val);

    return NULL;
}

int main(int argc, char** argv) {
    pthread_t tids[N];

    for (int i = 0; i < N; ++i) {
        pthread_create(&tids[i], NULL, thread_func, (void*)(intptr_t)i);
    }

    printf("main:\t%p, %d\n", &val, val);

    for (int i = 0; i <N; ++i) {
        pthread_join(tids[i], NULL);
    }
}
