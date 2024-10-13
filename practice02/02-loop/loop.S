    .intel_syntax noprefix
    .global main
main:
    xor rbx, rbx
loop:
    add rbx, 1
    mov rdi, rbx
    call writei64
    mov rcx, rbx
    sub rcx, 20
    jl loop
    call finish


