// ** Условие **
// Массив на 200 элементов типа int.
// Подается на вход индекс и значение.
// Требуется вывести старое значение по индексу
// и обновить его на введенное

    .intel_syntax noprefix
    .global main
    .text
main:
    call    readi64
    cmp     rax, -1
    jz      fin
    mov     r12, rax // в r12 index

    call    readi32
    mov     r13, rax // в r13 value

    // BREG + IREG * SCALE + OFFSET
    // SCALE = 1, 2, 4, 8

    // lea = поместить в регистр адрес выражения

    // 1. так не получится, т.к. BREG -- это _один_ регистр
    // lea  r14, [rip + arr + r12 * 8]

    // 2. так не получится, т.к. OFFSET -- это число
    // lea  r14, [rip + r12 * 8 + arr ]

    lea     r14, [rip  + arr]     // r14 = &array[0]
    lea     r14, [r14  + r12 * 8] // r14 = &array[0] + index * 8

    mov     rdi, [r14] // rdi = *(&array[0] + index * 8) = array[8]
    call    writei64
    mov     [r14], r13 // array[8] = r13

    jmp     main

fin:
    call    finish


    .data
arr:
  .skip 200 * 8, 0
