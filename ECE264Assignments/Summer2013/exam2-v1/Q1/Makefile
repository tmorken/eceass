q1: q1.c
	gcc -g -Wall -Wshadow q1.c -o q1

test: q1
	./q1 fint finb fout
	diff fout sample

clean:
	rm -f q1 fout *~

