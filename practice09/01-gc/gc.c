#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "gc.h"


typedef void (*finalizer_t)(void *ptr, size_t size);

struct allocation {
    void *ptr; // указатель на область памяти
    size_t size; // размер
    finalizer_t finalizer; // функция, которую следует вызвать перед free
    bool alive; // достижимость

    struct allocation *next; // для обработки случая 2 из test.с может потребоваться список аллокций
};

struct alloc_table {
    size_t size;  // текущий размер массива аллокаций
    size_t capacity; // максимальный размер массива аллокаций
    struct allocation *allocs; // массив аллокаций.
};

static struct alloc_table alloc_table;
static void* stack_bottom;

static void add_allocation(void *ptr, size_t size, finalizer_t finalizer) {
    struct allocation tmp = {
                        .ptr = (void*)ptr,
                        .size = size,
                        .finalizer = finalizer,
                        .alive = false,
                        .next = NULL
    };

    // 1. if (в массиве allocs нет места (size == capacity) под новую аллокацию tmp)
    //          выделить больше места (например, удвоить массив allocs, обновить capacity)
    //          с помощью malloc/memcpy/free или realloc

    // 2. добавить новую аллокацию tmp в конец массива allocs
}

void *gc_malloc(size_t size, finalizer_t finalizer) {
    void *ptr = malloc(size);
    if (ptr)
        add_allocation(result, size, finalizer);
    return ptr;
}

static allocation* find_allocation(void *ptr) {
    for (int i = 0; i < alloc_table.size; i++){
        // if (адрес ptr в находится внутри alloc_table[i])
        //      return &alloc_table[i];
    }
    return NULL;
}

#define PTR_SIZE (sizeof(void *))

// Аллокация считается достижимой, если указатель на неё есть в стеке либо в другой достижимой аллокации.
// queue -- список для достижимых аллокаций
static void follow_ptr(void* ptraddr, struct allocation **queue) {
    void *ptr;
    memcpy(&ptr, ptraddr, PTR_SIZE);

    allocation* a = find_allocation(ptr);
    if (a != NULL) {
        a->alive = true;
        // добавить allocation в список queue
    }
}

void gc_collect_impl(uintptr_t stack_top) {
    for (size_t i = 0; i < alloc_table.size; ++i) {
        alloc_table.allocs[i].alive = false;
    }

    // Аллокация считается достижимой, если указатель на неё есть в стеке либо в другой достижимой аллокации.
    // queue -- список для достижимых аллокаций
    struct allocation *queue = NULL;

    // разбор стека
    for (uintptr_t stack = stack_top; stack + PTR_SIZE <= stack_bottom; stack += PTR_SIZE) {
        follow_ptr((void*)stack, &queue);
    }

    // разбор достижимых аллокаций
    while (queue) {
        for (...) {
            // при разборе достижимых из стека аллокаций в очередь могут добавиться новые аллокации!
            follow_ptr(mem, &queue);
        }
    }

    // пройти по списку аллокции
    for (size_t i = 0; i < alloc_table.size; ++i) {
        if (!alloc_table.allocs[i].alive) {
            //1. вызвать finalizer
            //2. вызвать free
        }
    }

}

void gc_init(char **argv) {
    stack_bottom = (void*)argv;
}



allocs
                next              next
[       ][      208][       ][    100][       ][       ]
100      136        172      208


queue --> 136