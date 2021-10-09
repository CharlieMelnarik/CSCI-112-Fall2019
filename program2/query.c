#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "class.h"

void queryUser(node_t* classes) {

    char type;

    do {
       type = askUser();
       switch (type) {
       case 'n':
           printClassByNum(classes);
           break;
       case 'd':
           printClassesDay(classes);
           break;
       case 'p':
           printClassesProf(classes);
           break;
       case 'q':
           break;
       default:
           printf("ERROR: bad query response %c\n", type);
           exit(EXIT_FAILURE);
       }  
    } while (type != 'q');

    return;
}

char askUser() {

    char type, nl;

    printf("Choices:\nn - print class given number\
            \nd - print all classes for a given day combo \
            \np - print all classes for a given professor \
            \nq - quit\n");

    // make sure to "eat" the nl (throw it away)
    scanf("%c%c", &type, &nl);
    return type;
}

