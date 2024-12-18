* GDB
    * basic commands
        * run
        * step/next/finish/continue
        * b [file]:line
        * info b
        * p var
        * p $rax
        * layout src
        * layout asm
        * layout regs
    * binary_tree.cpp
        * cat random_numbers.txt | ./bt > /dev/null
        * stack
            * gdb ./bt
            * run < random_numbers.txt
            * bt --- показать стек (gdb ищет prologue/epilogue)
            * info frame -- показать текущий кадр
            * up/down -- перейти на кадр выше/ниже по стеку
        * coredump
            * ulimit -a
            * ulimit -S -c unlimited
            * ls /var/lib/apport/coredump
            * gdb ./bt core
        * without debug symbols
            * layout asm
            * p/d *((int*)($rbp - 0x4)
            * p/d $rax
        * conditional breakpoints: b 24 if val == 0
    * присоединиться к запущенному процессу
        * sudo gdb -p [pid]
    * complicated.cpp
        * ищем где i становится 0
        * start --- тоже самое что b main потом r
        * watch i --- останавливается когда переменная меняется)
        * conditional watch point: watch i if i == 0
        * history
            * target record-full
            * reverse-next/reverse-step/reverse-continue
    * pretty
        * set print pretty on
        * call get_distance(3, 3)
        * set points[0].x = 55
        * source `custom_point_printer.py`
    * ~/.gdbinit
        * set auto-load safe-path / (.gdbinit для каждого проекта)
        * set history save on (общая история)
    * project/.gdbinit
        * la src
        * focus cmd
        * b 22
        * source `custom_point_printer.py`
        * set print pretty on

