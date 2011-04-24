all: first
first:
	gcc -ggdb -ansi -Wall -pedantic first.c -o first

clean:
	rm -f *.o first
