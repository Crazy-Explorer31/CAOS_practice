    .intel_syntax noprefix
    .global main
main:
    call readi64
    mov rbx, rax

    call readi64
    mov rdi, rax

    cmp rdi, rbx
    jge label

    mov rdi, rbx
label:
    call writei64
    call finish
