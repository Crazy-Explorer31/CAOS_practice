    .intel_syntax noprefix
    .global main
    .text
main:
    call readi64

    mov  rcx, rsp
1:
    xor  rdx, rdx
    div  qword ptr [rip + dec]
    push rdx
    cmp  rax, 0
    jne  1b

    xor  rsi, rsi
    mov  rbx, 1
1:
    pop  rax
    mul  rbx
    add  rsi, rax

    mov  rax, rbx
    mul  qword ptr [rip +  dec]
    mov  rbx, rax

    cmp  rcx, rsp
    jnz  1b

    mov  rdi, rsi
    call writei64

    call finish

    .data
dec: .int 10
