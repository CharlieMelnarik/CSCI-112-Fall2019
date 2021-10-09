#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "class.h"

void printClassByNum(class_t* classes, int n) {

    // find the class number entered by user and print it
    char answer[15];
    char nl;
    int i;

    printf("Enter class number: ");
    // read the class number (with spaces) and eat the new line
    scanf("%[^\n]%c", answer, &nl); 

    for (i = 0; i < n; ++i) {
        if (strcmp(answer, classes[i].cnumber) == 0) {
            printOneClass(classes[i]);
            break;
        }
    }
    if (i == n) {
        printf("ERROR: Bad Class Number\n");
    }
    return;
}

void printClassesProf(class_t* classes, int n) {

    // find the professor's last name entered by user and print
    // all classes that have that professor teaching it
    int i;
    int count = 0;

    char answer[70];
    char nl;

    printf("Enter Professor's Last Name: ");
    scanf("%s", answer);
    // eat the new line
    scanf("%c", &nl);

    printf("List of classes for Professor %s:\n", answer);
    for (i = 0; i < n; ++i) {
        if (strncmp(classes[i].professor, answer, strlen(answer)) == 0) {
            printOneClass(classes[i]);
            ++count;
        }
    }
    if (count == 0) {
        printf("ERROR: Bad Professor Name\n");
    }
    return;
}

void printClassesDay(class_t* classes, int n) {

    // find all classes taught on the days input by the user
    // and print them
    char day[4];
    char nl;

    int i;

    printf("Enter class days to print (MWF or TR): ");
    scanf("%s", day);
    scanf("%c", &nl); // eat the newline

    if (strcmp(day,"MWF") != 0 && strcmp(day,"TR") != 0) {
        printf("ERROR: bad day input %s\n", day);
        exit(EXIT_FAILURE);
    }

    printf("List of classes for days %s:\n", day);
    for (i = 0; i < n; ++i) {
        if (strcmp(classes[i].cdays, day) == 0) {
            printOneClass(classes[i]);
        }
    }
    return;
}

void printOneClass(class_t c) {
    // helper function to keep from doing this complicated 
    // print everywhere
    printf("%-35s %-11s %-25s   %-3d   %-5s %s\n", c.ctitle, 
           c.cnumber, c.professor, c.no_seats, c.cdays, c.ctime);

    return;
}

void queryUser(class_t* classes, int n) {

    char type;

    do {
       type = askUser();
       switch (type) {
       case 'n':
           printClassByNum(classes, n);
           break;
       case 'd':
           printClassesDay(classes, n);
           break;
       case 'p':
           printClassesProf(classes, n);
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

void parseLine(class_t* class, char* line) {
   
    // this function is working on one line and one data structure
    // in the array
   
    char *result;
    char copy_line[301];

    int i;

    // save the contents of the line just in case I want to use it
    strcpy(copy_line,line);

    // pull off the csci number and put in data structure
    result = strtok(copy_line,",");
    strcpy(class->cnumber,result);

    // pull off the title of the class and put in data structure
    result = strtok(NULL, ",");
    strcpy(class->ctitle, result);    

    // don't use next string - crn
    result = strtok(NULL, ",");

    // get the number of seas - this is a number, not string
    result = strtok(NULL, ",");
    class->no_seats = atoi(result);

    // throw away the next 2 numbers
    for (i = 0; i < 3; ++i) {
        result = strtok(NULL, ",");
    }
    // now get the professor's name and store in data structure
    strcpy(class->professor, result);

    // throw out the next 3 items
    for (i = 0; i < 4; ++i) { 
        result = strtok(NULL, ",");
    }

    // now we have the days and time together so we need to break
    // that up since it is not separated by a ,
    BreakUpDayTime(class, result);
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

int readClasses(class_t* classes) {

    FILE* inputf = fopen("classes_mod.csv","r");

    char line[301];

    int i = 0;

    // read each line and put the needed information from that line 
    // into one struct
    while (fgets(line,300,inputf) != NULL) { 
        parseLine(&classes[i], line);
        ++i;
    }
    fclose(inputf);

    // this contains the number of classes read - in other words, 
    // the size of the array
    return i;
}
    
int main(int argc, char** argv) {
    
    class_t classes[30];

    int numc; // number of classes read in

    // read in the file and place data in the array of data structures
    numc = readClasses(classes);

    // Stay in this function until 'q' hit to handle user's requests
    queryUser(classes, numc);

    return(0);
}
     
