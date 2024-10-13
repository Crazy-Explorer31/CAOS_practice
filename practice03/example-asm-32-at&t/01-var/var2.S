
.global main
.text
main:
    mov x, %eax
    call writei32
    incl x
    call finish

.data
x:  .int 43
