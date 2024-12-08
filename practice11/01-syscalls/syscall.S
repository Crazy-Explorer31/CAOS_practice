#include <sys/syscall.h>
    .intel_syntax noprefix
    .global main
main:
    mov rax, SYS_exit      // Кладем в rax номер системного вызова для SYS_exit
    mov rdi, 42            // Кладем в rdi код возврата (42), используя xor для оптимальности
    syscall                //  Выполняем системный вызов



