build: rop

# -O0: do not optimize our dummy main.c
# -no-pie: to see same addresses in dump and in gdb
# -z noexecstack: switch off anoying warning "missing .note.GNU-stack section implies executable stack"
rop: main.c rop.S functions.S Makefile
	gcc -O0 -g -no-pie -z noexecstack main.c rop.S functions.S -o ./rop
	objdump -fdh ./rop > rop.dump

clean:
	rm -rf *.o ./rop rop.dump

