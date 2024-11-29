#include "gc.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void finalizer(void *ptr, size_t size) {
    printf("finalizer called: %zu\n", size);
}

int main(int argc, char **argv) {
    gc_init(argv);

    size_t size = 100; // алгоритм попытается любую переменную интерпретировать как указатель
                       // и эту переменную тоже!

    // случай 1: пытается интерпретировать каждые sizeof(void *) байт из стека как указатель
    void* p1 = gc_malloc(size, finalizer);

    // случай 2:  Таким же образом проходит по всем достижимым аллокациям, находя в них указатели
    // и помечая достижимые аллокации.
    int** p2 = (int**) gc_malloc(2 * sizeof(int*), finalizer);
    p2[0] = (int*) gc_malloc(size * sizeof(int), finalizer);
    p2[1] = (int*) gc_malloc(size * sizeof(int), finalizer);

    gc_collect();
}



void f1() {
    size_t size = 100;
    void* p1 = malloc(size);
}


void f2() {
    int** p2 = (int**) malloc(2 * sizeof(int*));
    p2[0] = (int*) malloc(size * sizeof(int));
    p2[1] = (int*) malloc(size * sizeof(int));
}

stack
---------------------- stack_bottom 32
p2 -->100

---------------------- stack_top  16

heap
------------------

100: [300,  400                           ]     //malloc(2 * sizeof(int*));
      p2[0] p2[1]

300: [                   ] malloc(size * sizeof(int));
400: [                   ] malloc(size * sizeof(int));

-------------------










