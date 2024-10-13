    .intel_syntax noprefix
    .global main
.global main
.text
main:
    lea r14, [rip + array]

    mov r12, 0
    mov r13, 10
loop1:
    mov dword ptr [r14 + r12 * 4], 1
    inc r12
    cmp r12, r13
    jl loop1

    mov r12, 0
loop2:
    mov edi, [r14 + r12 * 4]
    call writei32
    inc r12
    cmp r12, r13
    jl loop2

    call finish
.data
    array:  .skip 4 * 10
