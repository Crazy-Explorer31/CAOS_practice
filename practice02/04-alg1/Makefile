build: alg1

clean:
	rm -rf alg1

alg1: alg1.S
	gcc -g alg1.S simpleio_x86_64.S -o alg1

dump: alg1
	objdump -fhd alg1 > alg1.dump


