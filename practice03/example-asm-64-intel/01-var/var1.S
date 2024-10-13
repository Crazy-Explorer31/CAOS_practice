// Почему оно падает?
    .intel_syntax noprefix
    .section .text
    .global main
main:
    // <<догадывается>> о том, сколько надо считать с адреса [rip + x]
    // по размеру регистра-назначения edi
    mov  edi, [rip + x]
    call writei32
    // нужно подсказать (dword ptr), сколько нужно считать с адреса
    inc dword ptr [rip + x] // подсказываем
    call finish

x:  .int 43

