clean:
	rm -rf 01-endian 02-test.S 03-var

01-endian: 01-endian.S
	gcc -z noexecstack -g 01-endian.S -o 01-endian
	objdump -fdh 01-endian > 01-endian.dump

02-test: 02-test.c
	gcc -S -masm=intel -fverbose-asm -O0 02-test.c -o 02-test.S

03-var: 03-var.c
	gcc -g -O0 03-var.c -o 03-var

03-run:
	gdb -x 03-gdb.x ./03-var
