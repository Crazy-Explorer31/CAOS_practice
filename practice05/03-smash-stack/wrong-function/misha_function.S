        .intel_syntax noprefix
        .global process
process:
        mov $4, %eax
        mov %ebp, %esp
        pop %ebp
        ret
