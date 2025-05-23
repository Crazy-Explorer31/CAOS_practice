// ** Условие **
// Массив на 200 элементов типа int.
// Подается на вход индекс и значение.
// Требуется вывести старое значение по индексу
// и обновить его на введенное

    .global main
main:
    call    readi32         // прочитали индекс
    cmp     $-1, %eax
    jz      fin


    mov     %eax, %ebx
    call    readi32         // читаем новое значение-
    mov     %eax, %edx

    mov     $arr, %edi      // кладем адрес начала массива в %edi. Используем $, чтобы получить адрес
    shl     $2, %ebx        // умножаем индекс на 4, так как хотим за одно значение индекса пропускать 4 байта (1 int)
    add     %ebx, %edi      // прибавляем наш сдвиг кратный 4 к началу массива
    mov     (%edi), %eax    // в edi сейчас находится како1-то адрес, чтобы получить значение по этоому адресу используем ()

    // ADDR(OFFSET, INDEX, MULTIPLY) -> ADDR + OFSET + INDEX * MULT

    // могли бы то же самое записать по-другому:
    // same as:   mov (%edi, %ebx, 4), %eax     --  value(edi + ebx * 4) -> eax
    // в main или arr лежит просто адрес на следующую инструкцию, поэтому можем просто
    // прибавлять сразу к метке
    // or:        mov arr(%edi, %ebx, 4), %eax  --  value(arr + edi + ebx * 4) -> eax
    // our case:  mov arr(, %ebx, 4), %eax      --  value(arr + ebx * 4) -> eax

    call    writei32

    mov     %edx, (%edi)    // складываем новое значение по адресу, указанному в edi

    jmp     main

fin:
    call    finish

    .data
arr:
    .skip 200 * 4               // 200 значение типа int (4 байта)

