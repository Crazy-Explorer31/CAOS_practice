build: alg2

clean:
	rm -rf alg2

alg2: alg2.S
	gcc -g alg2.S simpleio_x86_64.S -o alg2

dump: alg2
	objdump -fhd alg2 > alg2.dump


