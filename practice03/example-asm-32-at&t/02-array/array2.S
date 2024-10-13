.global main
.text
main:
    mov $array, %esi
    mov $0, %edi
    mov $10, %ebx
loop1:
    mov $1, (%esi, %edi, 4)
    incl %edi
    cmp %ebx, %edi
    jl loop1

    mov $0, %edi
loop2:
    mov (%esi, %edi, 4), %eax
    call writei32
    incl %edi
    cmp %ebx, %edi
    jl loop2

    call finish
.data
    array:  .skip 4 * 10
