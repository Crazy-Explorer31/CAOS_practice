1. Адресация

at&t 32, прямая (адрес является операндом) и косвенная (адрес сохранен в другом регистре)
```
mov $1, val --- прямая: занести 1 в содержимое ячейки val
mov val, %eax --- прямая: занести содержимое ячейки val в eax


mov $val, %eax  --- косвенная: занести адрес val в eax
mov $1, 0(%eax) --- косвенная: занести 1 в ячейку адрес который = eax + 0

val: .int 4
```


intel 64, косвенная (адрес сохранен в другом регистре; в регистре rip)

```
mov edi, [rip + val] // занести содержимое ячейки val в eax
mov [rip + val], edi // занести содержимое edi в ячейку, адрес которой val
mov dword ptr [rip + val], 1 // занести 1 в ячейку, адрес которой val

val: .int 4
```



2. Как в gdb посмотреть переменную?

at&t 32
```
.global main
.text
main:
    mov x, %eax
    call writei32
    incl x
    call finish

.data
x:  .int 43

```

intel 64
```
    .intel_syntax noprefix
    .section .text
    .global main
main:
    mov  edi, [rip + x]
    call writei32
    inc dword ptr [rip + x]
    call finish

    .section .data
x:  .int 43
```



```
p/d *((int*)&x)
```
или "узнать адрес переменной по команде"
at&t 32
```
layout asm
incl 0x56559008
p/d *(0x56559008)
```

intel 64
```
layout asm
incl 0x555555558010
p/d *(0x555555558010)
```

3. Как в gdb посмотреть массив?
```
.global main
.text
main:
...
    call finish
.data
    array:  .skip 4 * 10
```
```
p *((int*)&array)@10
```
4. посмотреть содержание .data секции
objdump -s -j .data ./04

5. посмотреть файл в hex
hexdump ./04


6. stack

```
0000 0000

---------

           rsp (64) или esp (32)
---------


ffff ffff
```

32
```
push: esp -= sizeof(var); *esp = var;
pop:  var = *esp; esp += sizeof(var);
```

64
```
push: rsp -= sizeof(var); *rsp = var;
pop:  var = *rsp; rsp += sizeof(var);
```


Посмотреть стек
32
```
p/x $esp
addr
p *((int*)addr)@len
```

64
```
p/x $rsp
addr
p *((long long int*)addr)@len
```

```
p *((long long int*)$rsp)@len
```
