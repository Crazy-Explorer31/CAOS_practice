Заметки:
* VirtualBox + Ubuntu: https://ldvsoft.net/2017/09/10/ubuntu-course.html
* в Ubuntu необходимо поставить:
    * sudo apt install build-essential
    * sudo apt install gcc-multilib (чтобы работало simpleio под m32)
* * Tmux (очень удобно, если разрабатываешь клиент и сервер)
    * apt install tmux

    ```
    tmux new -s session
    tmux ls
    tmux attach -t session
    ```

    * These are some useful tmux command that can be triggered using prefix ctrl+b then following keys:

        * c : Create a new window.

        * 0 to 9 : Select windows 0 to 9.

        * & : Kill the current window.

        * l : Move to the previously selected window.

        * n : Change to the next window.

        * d : Detach the current client.

        * " : Split the current pane into two, top and bottom.

        * % : Split the current pane into two, left and right.

        * arrow keys : switch between panes

        * [ you can use your normal navigation keys to scroll around (eg. Up Arrow or PgDn). Press q to quit scroll mode.

* Не забывайте про tab в Makefile.

* Команды.
    * [Справочник команд](https://www.felixcloutier.com/x86/)
    * [Как читать нотацию?](https://stackoverflow.com/questions/15017659/how-to-read-the-intel-opcode-notation)

* Disasm.
    ```
    objdump -fhd sum > sum.dump
    ```
* GDB.
    * [Документация](https://sourceware.org/gdb/onlinedocs/gdb/)
    ```
    gdb hello.elf
    b main
    run
    p/x $eax
    p/d $ebx
    info b
    b sum.S:7
    s
    continue
    ```
* [Текстовый оконный интерфейс gdb (tui)](https://sourceware.org/gdb/onlinedocs/gdb/TUI-Commands.html)

    layout -- окно
    ```
    tui layout src
    tui layout asm
    tui layout regs general
    ```
    ctrl + x + o -- переключение между layout

