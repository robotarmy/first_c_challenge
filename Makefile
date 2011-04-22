all:
	gcc -ansi -Wall -pedantic first.c -o first

clean:
	rm -f *.o first
