clean:
	rm -rf var1 var2

var1: var1.S
	gcc -g -z noexecstack var1.S simpleio_x86_64.S -o var1

var2: var2.S
	gcc -g -z noexecstack var2.S simpleio_x86_64.S -o var2
	objdump -s -j .data ./var2


