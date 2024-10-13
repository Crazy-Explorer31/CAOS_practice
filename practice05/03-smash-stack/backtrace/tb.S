    .intel_syntax noprefix
    .global print_tb

    .text
print_addr:
    push rbp
    mov rbp, rsp

    lea rsi, [rip + func_table]

    // вместо того, что ниже надо:
    // 1. здесь нужно пройти в цикле по табличке
    // 2. найти ближайщую к аргументу функцию
    // 3. вывести ее имя на экран

    call puts

    // хорошо бы тут разобраться с возвращаемым значением

    pop rbp
    ret

print_tb:
    push rbp
    mov rbp, rsp

    lea rdi, [rip + print_tb_name]
    call puts

    call print_addr

    mov r12, rbp
loop:
    // надо достать RA
    call print_addr

    test rax, rax
    jnz done

    // надо перейти к следующему кадру стека
    jmp loop

done:

    pop rbp
    ret

foo_name:
    .asciz "foo"
bar_name:
    .asciz "bar"
main_name:
    .asciz "main"
print_tb_name:
    .asciz "print_tb"
func_table:
    .quad foo_name, foo, 0
    .quad bar_name, bar, 0
    .quad main_name, main, 1
    .quad print_tb_name, print_tb, 0

// интересно, для чего последнее поле 0 или 1?
