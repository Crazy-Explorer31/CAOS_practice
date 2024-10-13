    .intel_syntax noprefix
    .global main
    .text
main:

    mov rdi, 3
    mov rsi, 2
    call sum

    mov rdi, rax
    call writei64

    lea rdi, [rip + HELLO_WORLD]
    call strlen

    mov rdi, rax
    call writei64

    call finish

    .data
HELLO_WORLD:
    .asciz "Hello, world!"
