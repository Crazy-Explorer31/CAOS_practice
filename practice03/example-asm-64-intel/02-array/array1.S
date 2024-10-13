    .intel_syntax noprefix
    .global main
    .text
main:
    call    readi64
    cmp     rax, -1
    jz      fin
    mov     r12, rax

    call    readi32
    mov     r13, rax

    lea     r14, [rip  + arr]
    lea     r14, [r14  + r12 * 8]

    mov     rdi, [r14]
    call    writei64
    mov     [r14], r13

    jmp     main

fin:
    call    finish


    .data
arr:
  .skip 200 * 8, 0


// в чем разница .data --> .bss ? размер файла и заполнение
//    .bss
//arr:
//    .skip 2000 * 8, 0
