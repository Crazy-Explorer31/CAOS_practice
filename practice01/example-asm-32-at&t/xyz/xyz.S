// Что делает программа?
// Где ошибка?

    .global main
main:
    call readi32
    movl %eax, %ebx

    call readi32
    movl %eax, %ecx

    movl %ebx, %edx
    movl %ecx, %edx
    movl %edx, %ecx

    movl %ebx, %eax
    call writei32

    movl %ecx, %eax
    call writei32

    call finish
