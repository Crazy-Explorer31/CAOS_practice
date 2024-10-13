// Почему оно падает?

.section .text

    .global main
main:
    mov x, %eax
    call writei32
    incl x // x = x + 1
    call finish

x:  .int 43


