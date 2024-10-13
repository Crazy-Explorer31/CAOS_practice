    .intel_syntax noprefix
    .global main
main:
    call readi64
    mov  rbx, 2
    and  rax, rbx
    shr  rax,  1
    mov  rdi, rax
    call writei64

    call finish
