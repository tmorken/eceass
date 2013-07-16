q3: list.h list.c main.c
	gcc -g -Wall -Wshadow list.c main.c -o q3

test: q3
	./q3 > output
	diff output sample

memory: q3
	valgrind --leak-check=full --verbose ./q3 

clean:
	rm -f q3 output* *~


