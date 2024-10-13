    .intel_syntax noprefix
    .global main
main:
    call readi64
    mov r12, rax

    call readi64
    mov r13, rax

l1:
    cmp r13, r12
    je l3
    ja l2
    xchg r13, r12
l2:
    sub r13, r12
    jmp l1
l3:
    mov rdi, r12
    call writei64

    call finish
