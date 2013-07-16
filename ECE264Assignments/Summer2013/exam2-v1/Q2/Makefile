q2: thing.h thing.c main.c
	gcc -g -Wall -Wshadow thing.c main.c -o q2

test: q2
	./q2 > output
	diff output sample

memory: q2
	valgrind --leak-check=full --verbose ./q2 

clean:
	rm -f q2 output* *~
