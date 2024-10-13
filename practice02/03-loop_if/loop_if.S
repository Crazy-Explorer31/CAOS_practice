    .intel_syntax noprefix
    .global main
main:
    xor rax, rax

loop:
    call readi64
    mov rbx, rax
    mov rcx, 10
    sub rbx, rcx
    jz done
    jmp loop
done:
    call finish


