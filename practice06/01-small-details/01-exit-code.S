    .intel_syntax noprefix
    .global main

main:
    push    rbp
    mov     rbp, rsp
/*
    code
*/

    mov     rsp, rbp
    pop     rbp

    xor     rax, rax
    //mov rax, 1

    ret
