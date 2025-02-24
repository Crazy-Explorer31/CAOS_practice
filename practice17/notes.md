* 1111111111111111111111111111222222222222222222222222222222

* Threads vs Process. fork() is how you create new processes in Unix. When you call fork, you're creating a copy of your own process that has its own address space. This allows multiple tasks to run independently of one another as though they each had the full memory of the machine to themselves.
	* у процессов разные адресные пространства
	* если один процесс падает, то на остальные процессы это не влияет

* Here are some example usages of fork:

	* Your shell uses fork to run the programs you invoke from the command line.

	* Web servers like apache use fork to create multiple server processes, each of which handles requests in its own address space. If one dies or leaks memory, others are unaffected, so it functions as a mechanism for fault tolerance.

	* Google Chrome uses fork to handle each page within a separate process. This will prevent client-side code on one page from bringing your whole browser down.

* 01-fork-simple.c
	* Почему bye вывелось два раза? fork создает дочерний процесс (копия родительского). В родительском процессе fork() возвращает pid дочернего процесса, в дочернем --- 0.
* 02-fork-join.c
	* Пусть у нас есть большой массив и мы хотим обработать две половинки параллельно (например, найти максимум). До fork у нас один процесс.
	После fork два процесса: родительский процесс делает свою половину работы и дожидается окончания дочернего процесса c помощью wait. Дочерний процесс делает свою половину работы и возвращает результат через exit.
	* exit завершает процесс и посылает результат родителю
	* родитель может узнать, как завершился дочерний процесс (normal/signal) и возвращаемое значение/номер сигнала. https://man7.org/linux/man-pages/man2/wait.2.html
* 03-fork-memory.c
	* пример показывает (будет выведено число 2), что у дочернего процесса <<копия памяти>> родительского (дочерний процесс делает sleep, чтобы родительский успел изменить массив).
* 04-fork-memory-cow.c
	* Kernel использует оптимизацию COW (copy-on-write): при вызове fork дублируются только записи о мэпппинге физ. адр. <--> вирт. адр. (TLB),  т.е. копия страниц не создаются. У двух процессов разные вирт. адреса, но они <<мапятся>> на одни и те же страницы (на тех же физических адресах). Если процессы только читают память, то так будет до конца их работы. Если один из процессов пытается что-то записать, это приводит к page fault (т.к. права изначально только на R), обработчик зage fault делает копию нужной страницы, ставит ей права RW, и уменьшает PC, чтобы еще раз сделать запись.
	```
		x = fork();
		if(x > 0) {
                arr[1] = 200; // page fault, copy page and update TLB
                arr[2] = 300; // just one memory access (no page fault)
				wait(&status);
        }
	```
* 04-fork-files.c
	* При fork копии <<объектов, описывающий файл в ядре>> (file descriptor objects) не создаются, т.е. у родительского и дочернего процессов будет один и тот же <<объект,	описывающий файл в ядре>> (т.е., например, общая текущая позиция в файле).

* 05-fork-tasks.c
	* если один процесс упадет, то остальные не пострадают
	* создается 5 задач (рулить марсоходом, вертеть солнечной батареей,
	поддерживать контакт с хьюстоном) и управляющий процесс
	* если он из задач упала (имитируем с помощью kill или exit в task5), то управляющий процесс ее перезапустит

* 06-fork-child.c, 06-fork-parent.c, 06-fork-connect.c
	* у родительского и дочернего может быть разный код
	* соединим их через pipe

*  07-fork-bomb.c, 07-fork-bomb.sh
```
:(){ :|:& };:
```

* :() – Defined the function called :
* :|: – Next it will call itself using programming technique called recursion and pipes the output to another call of the function ‘:’. 
The worst part is function get called two times to bomb your system.
* & – Puts the function call in the background so child cannot die at all and start eating system resources.
* ; – Terminate the function definition.
* : – Call (run) the function aka set the fork() bomb.
Here is more human readable code:

```
bomb() { 
 bomb | bomb &
}; bomb
```


