all:		stack.o reverser.o
	gcc -g stack.o reverser.o -o reverser

stack.o:    	stack.h stack.c
	gcc -g -c stack.c stack.c

reverser.o: 	reverser.c
	gcc -g -c reverser.c

clean:
	rm *.o
