* strace syscall_time.elf -- показать системные вызовы
    *
    ```
    int main() {
        char buf[4096];
        setvbuf(stdout, buf, _IOFBF, 4096); //_IOFBF  -- flush при FULL BF
        ...
        fflush(stdout); // иначе exit после } попробует fflush для локальной переменной из main
    }
    ```
* 'write_to_file.c'
    * main 2 write (справка по системным вызовам)
    * write/read не обязаны за одно обращение записать/считать весь буфер, нужно вызывать их в цикле
        * "It is not an error if this number is smaller than the number of bytes requested; this may happen for example because fewer bytes are actually available right now (maybe because we were close to end-of-file, or because we are reading from a pipe, or from a terminal), or because read() was interrupted by a signal."

        * `cat write_to_file.c | ./write_to_file`
    * как read возвращает EOF? (0) как read возвращает ошибку? (-1)
        * ssize_t --- signed чтобы вмещать -1
        * при вводе с клавиатуры Ctrl+D = End Of FILE (EOF)

* touch a.txt (создает файл нулевого размера)
