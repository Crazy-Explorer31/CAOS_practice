build: read_and_add

clean:
	rm -rf read_and_add

read_and_add: read_and_add.S
	gcc -z noexecstack -g simpleio_x86_64.S read_and_add.S -o read_and_add
