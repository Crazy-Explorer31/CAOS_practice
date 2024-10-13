build: stack1 stack2

clean:
	rm -rf stack1 stack2

stack1: stack1.S
	gcc -z noexecstack -g stack1.S simpleio_x86_64.S -o stack1


stack2: stack2.S
	gcc -z noexecstack -g stack2.S simpleio_x86_64.S -o stack2

