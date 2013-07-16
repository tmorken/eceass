q4: q4.c
	gcc -g -Wall -Wshadow q4.c -o q4

test: q4
	./q4 4 | sort > output4
	diff output4 result4
	./q4 6 | sort > output6
	diff output6 result6
	./q4 8 | sort > output8
	diff output8 result8

memory: q4
	valgrind --leak-check=full --verbose ./q4 6

clean:
	rm -f q4 output* *~

