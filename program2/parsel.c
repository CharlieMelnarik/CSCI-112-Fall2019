#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"

void parseLine(node_t** head, char* line) {
   
    // this function is working on one line and one data structure
    // in the array
   
    char *result;
    char copy_line[301];

    int i;

    class_t* cl = malloc(sizeof(class_t));

    // save the contents of the line just in case I want to use it
    strcpy(copy_line,line);

    // pull off the csci number and put in data structure
    result = strtok(copy_line,",");
    strcpy(cl->cnumber,result);

    // pull off the title of the class and put in data structure
    result = strtok(NULL, ",");
    strcpy(cl->ctitle, result);    

    // don't use next string - crn
    result = strtok(NULL, ",");

    // get the number of seas - this is a number, not string
    result = strtok(NULL, ",");
    cl->no_seats = atoi(result);

    // throw away the next 2 numbers
    for (i = 0; i < 3; ++i) {
        result = strtok(NULL, ",");
    }
    // now get the professor's name and store in data structure
    strcpy(cl->professor, result);

    // throw out the next 3 items
    for (i = 0; i < 4; ++i) { 
        result = strtok(NULL, ",");
    }

    // now we have the days and time together so we need to break
    // that up since it is not separated by a ,
    BreakUpDayTime(cl, result);
    listInsert(head,cl);
    return;
}

void BreakUpDayTime(class_t* class, char* str) {

    // this function breaks apart the days and time
    // they are separated by a space
    
    char* sub;
    sub = strtok(str, " ");
    strcpy(class->cdays, sub);
    sub = strtok(NULL, " ");
    strcpy(class->ctime, sub);

    return;
}
