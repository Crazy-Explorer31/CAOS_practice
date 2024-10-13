build: stack1 stack2

clean:
	rm -rf stack1 stack2

stack1: stack1.S
	gcc -m32 -g stack1.S simpleio_i686.S -o stack1


stack2: stack2.S
	gcc -m32 -g stack2.S simpleio_i686.S -o stack2

