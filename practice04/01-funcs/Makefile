clean:
	rm -rf 01-asm_func 02-asm_c_func 03-c_asm_func

01-asm_func: 01-asm_func.S
	gcc -z noexecstack -g 01-asm_func.S simpleio_x86_64.S -o 01-asm_func

02-asm_c_func: 02-asm_c_func.S 02-sum.c
	gcc -z noexecstack -g 02-asm_c_func.S 02-sum.c simpleio_x86_64.S -o 02-asm_c_func

03-c_asm_func: 03-c_asm_func.S 03-main.c
	gcc -z noexecstack -g 03-main.c 03-c_asm_func.S simpleio_x86_64.S -o 03-c_asm_func


