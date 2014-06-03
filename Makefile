# Makefile for Program 5's graph and drivers for IntList and modules - by Chris Dilday

Graphdr : Graphdr.o ListInt.o Graph.o
	gcc -ansi -Wall -Wextra -pedantic -o Graphdr Graphdr.o ListInt.o Graph.o

ListIntdr : ListIntdr.o ListInt.o
	gcc -ansi -Wall -Wextra -pedantic -o ListIntdr ListIntdr.o ListInt.o
	
Graphdr.o : Graphdr.c Graph.h Graph.c ListInt.h ListInt.c
	gcc -c -ansi -Wall -Wextra -pedantic Graph.c ListInt.c Graphdr.c
	
Graph.o : ListInt.h ListInt.c Graph.h Graph.c
	gcc -c -ansi -Wall -Wextra -pedantic ListInt.c Graph.c
	
ListInt.o : ListInt.h ListInt.c
	gcc -c -ansi -Wall -Wextra -pedantic ListInt.c

ListIntdr.o : ListInt.h ListIntdr.c
	gcc -c -ansi -Wall -Wextra -pedantic ListIntdr.c	

clean :
	rm ListInt.o ListIntdr ListIntdr.o Graph.o Graphdr Graphdr.o