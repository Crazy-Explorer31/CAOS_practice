    .intel_syntax noprefix
    .text
    .global f1
f1:
    lea  rax, [rip + str0]
    push rax
    push rax
    pop  rdi
    xor  rax, rax
    call printf
    pop  rdi
    ret

    .global str0
    .global str1
    .global str2
str0:
    .asciz "Fail\n"
str1:
    .asciz "Hello, "
str2:
    .asciz "world!\n"
