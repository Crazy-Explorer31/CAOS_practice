// https://shikaan.github.io/assembly/x86/guide/2024/09/08/x86-64-introduction-hello.html

    .intel_syntax noprefix
.section .text
    .global _start
_start:
    # The identifier for sys_write is 1.
    # size_t sys_write(uint fd, const char* buf, size_t count)
    mov rax, 1
    mov rdi, 1 # 1 identifies the standard output.
    lea rsi, [rip + msg]
    mov rdx, 14
    syscall

    # The identifier for sys_exit is 60.
    # int sys_exit(uint32_t status)
    mov rax, 60
    mov rdi, 0
    syscall

.section .data
  msg: .asciz "Hello, World!\n"
