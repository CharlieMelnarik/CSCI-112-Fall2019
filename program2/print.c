#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "class.h"

void printClassByNum(node_t* head) {

    // find the class number entered by user and print it
    char answer[15];
    char nl;
   
    node_t* node = head;

    printf("Enter class number: ");
    // read the class number (with spaces) and eat the new line
    scanf("%[^\n]%c", answer, &nl); 

    while (node != NULL) {
        if (strcmp(answer, node->cl->cnumber) == 0) {
            printOneClass(node->cl);
        }
	node = node->next;
    }
  
    return;
}

void printClassesProf(node_t* head) {

    // find the professor's last name entered by user and print
    // all classes that have that professor teaching it
   
    int count = 0;

    char answer[70];
    char nl;

    printf("Enter Professor's Last Name: ");
    scanf("%s", answer);
    // eat the new line
    scanf("%c", &nl);

    printf("List of classes for Professor %s:\n", answer);
    node_t* node = head;
    while (node != NULL){
	    if (strncmp(node->cl->professor, answer,strlen(answer)) == 0){
		    printOneClass(node->cl);
		    ++count;
	    }
	    node = node->next;
    }

    if (count == 0) {
        printf("ERROR: Bad Professor Name\n");
    }
    return;
}

void printClassesDay(node_t* head) {

    // find all classes taught on the days input by the user
    // and print them
    char day[4];
    char nl;

    node_t* node = head;

    printf("Enter class days to print (MWF or TR): ");
    scanf("%s", day);
    scanf("%c", &nl); // eat the newline

    if (strcmp(day,"MWF") != 0 && strcmp(day,"TR") != 0) {
        printf("ERROR: bad day input %s\n", day);
        exit(EXIT_FAILURE);
    }

    printf("List of classes for days %s:\n", day);
    while (node != NULL) {
        if (strcmp(node->cl->cdays, day) == 0) {
            printOneClass(node->cl);
        }
	node = node->next;
    }
    return;
}

void printOneClass(class_t* c) {
    // helper function to keep from doing this complicated 
    // print everywhere
    printf("%-35s %-11s %-25s   %-3d   %-5s %s\n", c->ctitle, 
           c->cnumber, c->professor, c->no_seats, c->cdays, c->ctime);

    return;
}
