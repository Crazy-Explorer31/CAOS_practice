struct FileWriteState {
    int fd;  // "файловый дескриптор", для вывода на стандартный поток вывода -
             // 1
    unsigned char *buf;  // указатель на буфер
    int bufsize;         // размер буфера
    int index;
};

static unsigned char buf[4096];
static struct FileWriteState stout_struct = {1, buf, 4096, 0};

struct FileWriteState *stout = &stout_struct;

void flush(struct FileWriteState *f) {
    if (если буфер не пуст) {
        надо сделать x86 asm вставку
            * https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html
                * см 01-syscalls/syscall.S
                * man 2 write
                * https://gcc.gnu.org/onlinedocs/gcc/Machine-Constraints.html
    }
}

void writechar(int c, struct FileWriteState *f) {
    if (если буфер полный) {
        flush(f);
    }
    f->buf[index++] = c;
    // а если сейчас стал полный?
}
