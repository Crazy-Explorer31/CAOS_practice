    .global main
    .text
main:
    call readi32

    movl %esp, %ecx
1:
    xorl %edx, %edx
    divl dec
    push %edx
    cmpl $0, %eax
    jne 1b

    xorl %esi, %esi
    mov $1, %ebx
1:
    pop %eax
    mull %ebx
    add %eax, %esi

    mov %ebx, %eax
    mull dec
    mov %eax, %ebx

    cmpl %esp, %ecx
    jnz 1b

    mov %esi, %eax
    call writei32

    call finish

    .data
dec: .int 10
