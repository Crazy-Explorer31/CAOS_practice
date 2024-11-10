build: vla

clean:
	rm -rf ./vla ./vla-safe1 ./vla-safe2

vla: vla.c Makefile
	gcc -g -O0 vla.c -o vla

vla-safe1: vla.c Makefile
	gcc -g -O0 -Wall -Werror  vla.c -o vla-safe1

valgrind: vla
	valgrind ./vla

# sanitizers:
# 	https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html
vla-safe2: vla.c Makefile
	gcc -g -O0  -fsanitize=address  vla.c -o vla-safe2

