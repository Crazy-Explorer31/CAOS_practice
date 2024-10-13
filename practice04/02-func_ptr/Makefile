build: func_ptr_asm

clean:
	rm -rf func_ptr_asm func_ptr_c

func_ptr_asm: func_ptr_asm.S
	gcc -z noexecstack -g func_ptr_asm.S simpleio_x86_64.S -o func_ptr_asm
	objdump -fdh ./func_ptr_asm >func_ptr_asm.dump

func_ptr_c: func_ptr_c.c
	gcc -z noexecstack -g func_ptr_c.c -o func_ptr_c



