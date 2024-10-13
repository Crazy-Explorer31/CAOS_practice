// Что делает программа?
// Где ошибка?

    .intel_syntax noprefix
    .global main
main:
    call readi64
    mov  rbx, rax

    call  readi64
    mov  rcx, rax

    mov  rdx, rbx
    mov  rdx, rcx
    mov  rcx, rdx

    mov r12, rcx // сохраним rcx в r12, тк writei64 <<портит>> rcx
    mov  rdi, rbx
    call writei64

    mov  rdi, r12
    call writei64

    call finish
