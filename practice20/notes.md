* libs
    * dpkg -l | grep libsdl2
    * apt search libsdl2
    * apt install libsdl2
    * apt install libsdl2-dev

* mmap
    * man 2 mmap
    ```
    #include <sys/mman.h>

    void *mmap(
        void *addr,    /* рекомендуемый адрес отображения, можно передавать NULL, если адрес не важен */
        size_t length, /* размер отображения */
        int prot,      /* аттрибуты доступа */
        int flags,     /* флаги совместного отображения */
        int fd,        /* файловый дескриптор файла */
        off_t offset   /* смещение относительно начала файла */
      );

    int munmap(void *addr, size_t length) /* освободить отображение */

    ```

    При ошибке `mmap` возвращает специальное значение `MAP_FAILED`.
    Чтобы детектировать ошибку, нужно проверять возвращаемое значение не на `NULL`,
    а на `MAP_FAILED`

    * Значения prot:

    	 PROT_NONE   Pages may not be accessed.
         PROT_READ   Pages may be read.
         PROT_WRITE  Pages may be written.
         PROT_EXEC   Pages may be executed.

    Использовать с битовым или: `PROT_READ | PROT_WRITE`

    * Значения flags:

        * `MAP_FIXED` - требует, чтобы память была выделена по указаному в первом аргументе адресу; без этого флага ядро может выбрать адрес, наиболее близкий к указанному.
        * `MAP_ANONYMOUS` - выделить страницы в оперативной памяти, а не связать с файлом. В таком случае значение файлового дескриптора игнорируется.
        * `MAP_SHARED` - выделить страницы, разделяемые с другими процессами; в случае с отображением на файл - синхронизировать изменения так, чтобы они были доступны другим процессам.
        * `MAP_PRIVATE` - в противоположность `MAP_SHARED`, не делать отображение доступным другим процессам. В случае отображения на файл, он доступен для чтения, а созданные процессом изменения, в файл не сохраняются.


* 01-mmap.c
    * echo "Hello world" > small_file.txt
    * синхронизация содержимого man 2 msync

* 02-mmap-multiple-processes.c
    * dd if=/dev/zero of=big_file.txt bs=4K count=2
    * в одну страницу:
        * 02-mmap-multiple-processes.elf big_file.txt 0
        * 02-mmap-multiple-processes.elf big_file.txt 0
    * в разные страницы:
        * 02-mmap-multiple-processes.elf big_file.txt 0
        * 02-mmap-multiple-processes.elf big_file.txt 1
    * hexdump big_file.txt
    * od -i big_file.txt

* 04-kill-proc.c,
    * 04-kill-proc.elf 1
    * mmap работает лениво:
        * виртуальной памяти выделяет, сколько надо;
        * физические страницы выделяются при чтении или записи, физические страницы освобождаются (swap), если памяти не хватает.
        * удобно работать с большими файлами: можно не думать, помещается ли в память
    * top --> VIRT/RES/SHR

> These three fields are related with to memory consumption of the
> processes. “VIRT” is the total amount
> of memory consumed by a process. This includes the program’s code, the data
> stored by the process in memory, as well as any regions of memory that have
> been swapped to the disk. “RES” is the memory consumed by the process in RAM,
> and “%MEM” expresses this value as a percentage of the total RAM available.
> Finally, “SHR” is the amount of memory shared with other processes.

    * ps -aux | wc -l --- общее число процессов сейчас; все хранят ссылки на одну libc.so (MAP_SHARED)

    * malloc --> MAP_AMONUMOUS

    * pidof 04-kill-proc.elf

      '63481`
    * cat /proc/63481/status
    * OOM Killer

