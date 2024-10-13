    .intel_syntax noprefix
    .global main
main:
    mov ah, 0xff
    shr ah, 2
    mov ah, 0xff
    sar ah, 2
    call finish
