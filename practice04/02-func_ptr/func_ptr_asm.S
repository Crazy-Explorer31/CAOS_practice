    .intel_syntax noprefix
    .global main
    .text
main:
    lea r12, [rip + operations]

    lea r13, [rip + my_inc]
    mov [r12 + 0 * 8], r13
    lea r13, [rip + my_dec]
    mov [r12 + 1 * 8], r13
    lea r13, [rip + my_show]
    mov [r12 + 2 * 8], r13

    mov r15, 0
    mov r14, [r12 + r15 *8]
    mov rdi, [rip + val]
    call r14

    mov r15, 2
    mov r14, [r12 + r15 *8]
    mov rdi, [rip + val]
    call r14

    call finish

    .global my_inc
my_inc:
    inc rdi
    mov rax, rdi
    ret

    .global my_dec
my_dec:
    dec rdi
    mov rax, rdi
    ret

    .global my_show
my_show:
    call writei64
    ret

.data
    operations:  .skip 8 * 3
    val: .int 5
