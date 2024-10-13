    .intel_syntax noprefix
    .global main
.section .text
main:
    mov byte ptr [rip + var], 1
    ret

var:
   .quad 0xBADC0FFEE0DDF00D

