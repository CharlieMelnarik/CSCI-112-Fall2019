#include <stdio.h>
#include "class.h"

//read classes function, literally reads the csv and parses each line
void readClasses(node_t** node) {

    FILE* inputf = fopen("classes_mod.csv","r");

    char line[301];

  

    // read each line and put the needed information from that line 
    // into one struct
    while (fgets(line,300,inputf) != NULL) { 
        parseLine(node, line);
        
    }
    fclose(inputf);

    // this contains the number of classes read - in other words, 
    // the size of the array
    return; 
}
    
