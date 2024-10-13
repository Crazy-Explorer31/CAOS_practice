        .intel_syntax noprefix
        .global main
main:
        push    rbp
        mov     rbp, rsp
        call process_call
        // надо сформировать аргументы для printf (число может быть 64-битным)
        call printf
        mov $0, %eax

        pop rbp
        ret

process_call:
	?
	?
        jmp process
