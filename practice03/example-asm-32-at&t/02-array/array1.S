    .global main
main:
    call    readi32
    cmp     $-1, %eax
    jz      fin

    mov     %eax, %ebx
    call    readi32
    mov     %eax, %edx

    mov     $arr, %edi
    shl     $2, %ebx
    add     %ebx, %edi
    mov     (%edi), %eax

    call    writei32


    mov     %edx, (%edi)
    jmp     main

fin:
    call    finish


//.data
//arr:
//  .skip 2000 * 4, 0


//в чем разница .data --> .bss ? размер файла; // заполнение
    .bss
 arr:
    .skip 2000 * 4, 0
