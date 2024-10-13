0. Архитектура Фон Неймана
    * char s[200]; scanf("%s", s); В чем проблема? Smashing stack for fun and profit.

1. Какое число в регистре знаковое или беззнаковое?

mov $0xFF, ah

2. Флаги (eflags register)

* CF -- флаг переноса. Используется для беззнаковых. CF = 1:
   * сложение беззнаковых x + y:  x + y >= 2^k
   * вычитание беззнаковых x - y: x < y

* OF -- флаг переполнения. Используется для знаковых. OF = 1, результат
    выходит за допустимый интервал [-2^(k-1), +2^(k-1) - 1].

* ZF -- флаг нуля. ZF = 1, результат равен нулю.

* SF -- флаг знака. Используется для знаковых. SF = 1, результат меньше 0.

p $eflags

3. Безусловный переход jmp

4. Сокращение для условных переходов

* Команды.
    * [Справочник команд](https://www.felixcloutier.com/x86/)
    * [Как читать нотацию?](https://stackoverflow.com/questions/15017659/how-to-read-the-intel-opcode-notation)

sub или cmp

* e - equal
* n - not
* g - greater (знаковые)
* l - less (знаковые)
* a - above (беззнаковые)
* b - below (беззнаковые)

Как коротко написать jnge?

5. Посмотреть к следующей практике, какие условия по флагам выполняются для команд

Например
* jz ZF=1
* js SF=1
* jc CF=1
* jo OF=1


Для любых чисел
* je            op1 = op2
* jne           op1 != op2

Для чисел со знаком
* ?   / jnge    op1 <  op2
* jle / jng     op1 <= op2
* jg  / jnle    op1 >  op2
* jge / jnl     op1 >= op2

Для чисел без знака
* jb  / jnae    op1 < op2
* jbe / jna     op1 <= op2
* ja  / jnbe    op1 > op2
* jae / jnd     op1 >= op2

6. Какому коду на C соответствует?
```
   cmp $0, %eax
   jle l1
   { code 1 }
   jmp l2
l1:
   { code 2 }
l2:
```

7. Какому коду на C соответствует?
```
l1:
   cmp $0, %eax
   jle l2
   { code }
   jmp l1
l2:
```

8. Какому коду на C соответствует?
```
movl $10, %eax
l:
   {code}
   dec %eax
   cmp $0, %eax
   jne l
```

9.

```
callee saved rbx, rsp, rbp, r12–r15.
```
