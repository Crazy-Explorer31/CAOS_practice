// https://stackoverflow.com/questions/57859857/what-is-the-calling-convention-for-floating-point-values-in-c-for-x86-64-in-syst

        .intel_syntax noprefix
        .text
        .global okay
okay:
        push rbp
        mov     rbp, rsp

        mulsd   xmm0, xmm0
	...
        movsd   [rdi], xmm0


        ...
        ret
