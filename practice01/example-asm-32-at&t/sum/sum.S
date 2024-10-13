    .global main
main:
    call readi32     // считали первое число
    movl %eax, %ecx  // сохранили его в ecx
    call readi32     // считали второе число в eax
    addl %ecx, %eax  // сложили первое и второе
    call writei32    // вывели результат
    call finish      // завершили программу
