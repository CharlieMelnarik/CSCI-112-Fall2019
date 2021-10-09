pgm1: main.o readclasses.o parsel.o query.o print.o linked_list_add1.o 
	gcc -o pgm1 main.o readclasses.o parsel.o query.o print.o linked_list_add1.o

main.o: main.c class.h
	gcc -c -g -Wall main.c
readclasses.o: readclasses.c class.h
	gcc -c -g -Wall readclasses.c
parsel.o: parsel.c class.h
	gcc -c -g -Wall parsel.c
query.o: query.c class.h
	gcc -c -g -Wall query.c
print.o: print.c class.h
	gcc -c -g -Wall print.c
linked_list_add1.o: linked_list_add1.c class.h
	gcc -c -g -Wall linked_list_add1.c
