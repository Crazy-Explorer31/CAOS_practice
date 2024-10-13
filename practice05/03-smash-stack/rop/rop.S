    .intel_syntax noprefix
    .global rop
rop:
    lea  rax, [rip + str1]
    push rax
    lea  rax, [rip + f1 + 1]
    push rax
    ret
