build: loop

clean:
	rm -rf loop

loop: loop.S
	gcc -g loop.S simpleio_x86_64.S -o loop

dump: loop
	objdump -fhd loop > loop.dump


