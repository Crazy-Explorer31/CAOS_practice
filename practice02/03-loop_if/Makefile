build: loop_if

clean:
	rm -rf loop_if

loop_if: loop_if.S
	gcc -g loop_if.S simpleio_x86_64.S -o loop_if

dump: loop_if
	objdump -fhd loop_if > loop_if.dump


