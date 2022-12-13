reverse: main.o reverse.o
	gcc main.o reverse.o -o reverse
main.o: main.c reverse.h
	gcc main.c -c -std=c99 -pedantic -Wall
reverse.o: reverse.c reverse.h
	gcc reverse.c -c -std=c99 -pedantic -Wall