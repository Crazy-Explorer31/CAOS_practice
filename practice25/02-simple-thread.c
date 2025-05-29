#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* func(void* smth) {
    sleep(5);
    printf("hello\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, func, NULL);
    pthread_join(tid, NULL);

}
