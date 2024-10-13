build: tb

# -O0: do not optimize our dummy main.c
# -no-pie: to see same addresses in dump and in gdb
# -z noexecstack: switch off anoying warning "missing .note.GNU-stack section implies executable stack"
tb: main.c tb.S Makefile
	gcc -O0 -g -no-pie -z noexecstack main.c tb.S -o ./tb
	objdump -fdh ./tb > tb.dump

clean:
	rm -rf *.o ./tb	tb.dump

