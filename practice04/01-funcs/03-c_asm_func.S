    .intel_syntax noprefix
    .global sum
sum:
    mov rax, rdi
    add rax, rsi
    ret
