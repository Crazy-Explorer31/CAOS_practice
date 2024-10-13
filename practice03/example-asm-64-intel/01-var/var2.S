    .intel_syntax noprefix
    .section .text
    .global main
main:
    mov  edi, [rip + x]
    call writei32
    inc dword ptr [rip + x]
    call finish

    .section .data
x:  .int 43

// в .data
// .byte - 1 байт
// .word - 2 байта
// .int  - 4 байта
// .quad - 8 байт

// для mov
// byte
// word
// dword
// qword
