0. gdb: layout regs

1. Чем call и ret отличаются от jmp?
```
   call func
==
   lea rax, [rip + 1f]
   push rax
   jmp func
   1f:

func:
   ret
==
func:
   pop rdx
   jmp rdx
```


2. cdecl:
    * первые 6 параметров передаются в регистрах rdi, rsi, rdx, rcx, r8, r9;
    * прочие параметры передаются (push) в стеке в обратном порядке  (пусть 9 параметров у функции: 6 через регистры, потом запушить 9, потом запушить 8, потом запушить 7)
    * параметры удаляет из стека тот, кто их туда положил (то есть вызывающая функция caller);
    * возвращаемое значение в регистре rax (а 128-битное — в паре rdx:rax);
    * caller-saved регистры: rax, rcx, rdx, rsi, rdi, r8-r11
    * callee-saved регистры: rbx, rsp, rbp, r12–r15;
    * перед инструкцией call указатель стека выровнен на 16 байт.

3. https://gcc.godbolt.org/

```
int many_sum(int a1, int a2, int a3, int a4, int a5, int a6, int a7,int a8);

int f() {
    return many_sum(1, 2, 3, 4, 5, 6, 7, 8);
}

int many_sum(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    int c = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8;
    return c;
}
```
gcc 14.2 -O0

```
f():
        push    rbp
        mov     rbp, rsp
        push    8
        push    7
        mov     r9d, 6
        mov     r8d, 5
        mov     ecx, 4
        mov     edx, 3
        mov     esi, 2
        mov     edi, 1
        call    many_sum(int, int, int, int, int, int, int, int)
        add     rsp, 16
        leave
        ret
many_sum(int, int, int, int, int, int, int, int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-20], edi
        mov     DWORD PTR [rbp-24], esi
        mov     DWORD PTR [rbp-28], edx
        mov     DWORD PTR [rbp-32], ecx
        mov     DWORD PTR [rbp-36], r8d
        mov     DWORD PTR [rbp-40], r9d
        mov     edx, DWORD PTR [rbp-20]
        mov     eax, DWORD PTR [rbp-24]
s        add     edx, eax
        mov     eax, DWORD PTR [rbp-28]
        add     edx, eax
        mov     eax, DWORD PTR [rbp-32]
        add     edx, eax
        mov     eax, DWORD PTR [rbp-36]
        add     edx, eax
        mov     eax, DWORD PTR [rbp-40]
        add     edx, eax
        mov     eax, DWORD PTR [rbp+16]
        add     edx, eax
        mov     eax, DWORD PTR [rbp+24]
        add     eax, edx
        mov     DWORD PTR [rbp-4], eax
        mov     eax, DWORD PTR [rbp-4]
        pop     rbp
        ret
```

Что тут происходит?
```
        mov     eax, DWORD PTR [rbp+16]
        add     edx, eax
        mov     eax, DWORD PTR [rbp+24]
        add     eax, edx
```

Почему rbp + 16?


4. visual studio code
    * sudo snap install --classic code
    * плагины: С/C++, C/C++ Extension Pack, C/C++  Themes, CMake, CMake Tools,  GNU Assembler Language Support, DamianKoper.gdb-debug (Ctrl+P --> ext install  ...)
    * пример проекта vscode-workspace
        * launch.json, tasks.json (переделал из https://github.com/newtonsart/vscode-assembly#vscode-assembly). В настройке Debugger: caos.
        * Debug console:
            * ввод/вывод readi64, writei64
            * p/d rbx
