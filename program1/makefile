program1: prgm1.o read.o
	gcc -o program1 prgm1.o read.o

prgm1.o: class.h prgm1.c
	gcc -c -g -Wall prgm1.c

read.o: class.h read.c
	gcc -c -g -Wall read.c
