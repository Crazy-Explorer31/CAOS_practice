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
    call my_strlen

    mov rdi, rax
    call writei64

    call finish

    .global sum
sum:
    mov rax, rdi
    add rax, rsi
    ret

    .global my_strlen
my_strlen:
    xor  r9, r9

loop:
    mov al, [rdi + r9 * 1]
    inc r9
    cmp al, 0
    jne  loop
    dec r9
    mov  rax, r9
    ret

    .data
HELLO_WORLD:
    .asciz "Hello, world!"
