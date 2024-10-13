    .intel_syntax noprefix
    .global main
main:
    call readi64     // считали первое число в rax (readi64 записывает результат в rax)
    mov rbx, rax     // сохранили его в rbx
    call readi64     // считали второе число в rax
    add rbx, rax     // сложили первое и второе rbx += rax
    mov rdi, rbx     // сохранили его в rdi
    call writei64    // вывели результат из rdi (writei64 вход из rdi)
    call finish      // завершили программу
