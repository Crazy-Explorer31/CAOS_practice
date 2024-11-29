
* lscpu --- что умеет процессор (flags: fpu, sse)

= FPU =

1. st(0)..st(x) --- 80 bit, long double

2. fdivp/fdirp --- st(0)/st(1), st(1)/st(0)

3. fldpi --- load pi, fild --- load integer (convert), fld1 --- load 1, fcomi -- compare (Unordered -- NaN)

4. gdb: 
	* layout regs 
	* p st0

= SSE =

1. xmm0..xmm7: 128b
	* 32b 32b 32b 32b
	* 64b 64b
2. packed mode: в один регистр помещаем несколько чисел
	* [..., ..., ..., 1.7] --- scalar режим
    * [1.1, 1.2, 1.4, 1.6] --- vector режим (еще называется packed)

3. соглешние о вызовых
	* передача параметров: xmm0, xmm1, ....
	* возвращаемое значение: xmm0 

4. addss --- add scalar single (i.e.float)

5. call printf
    * convert to double
    * x86_64-abi-0.99.pdf : %rax is used to indicate the number of vector arguments passed to a function requiring a variable number of arguments.

6.  movups -- packed 4 unaligned single, movupd -- packed 2 unaligned double
    * aligned --- адреса в памяти должны быть выравнены на 16 байт: movaps, movapd работает быстрее
7. xmm0 = [a, b], xmm1 = [c, d], SIMD (Single Instruction Multiple Data)
    * haddpd (горизонтально): [a + b, c + d]
    * addpd  (вертикально):  [a + c, b + d]
8. movhlps -- перенести 2 float (т.е. 1 double) из <<старшей части>> одного регистра, в <<младшую часть>> другого регистра, т.е. <<разобрать>> packed регистр на 2 части.
    * нужно т.к. printf не умеет работать с packed

= Dot Product =

1. запаковать в xmm по 2 float, применить вертикальное умножение и сложение в цикле, в конце применить горизонтальное сложение

2. intrinsic --- функция встроенная в компилятор (может внутри содержать кучу if про модель процессора (модели intel, например); на другие архитектуры непереносима).
