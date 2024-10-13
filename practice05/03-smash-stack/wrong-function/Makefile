build: wf

# -O0: do not optimize our dummy main.c
# -no-pie: to see same addresses in dump and in gdb
# -z noexecstack: switch off anoying warning "missing .note.GNU-stack section implies executable stack"
wf: main.S misha_function.S simpleio_i686.S Makefile
	gcc -O0 -m32 -g -no-pie -z noexecstack main.S misha_function.S simpleio_i686.S -o ./wf
	objdump -fdh ./wf > wf.dump

clean:
	rm -rf *.o ./wf wf.dump
	
