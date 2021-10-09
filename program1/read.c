// readfile 

#include <stdio.h>
#include "class.h"
#include <string.h>
// reads the file and parses out the peices needed
// returns the count of classes
int readfile(class_t* c)
{
	printf("readfile test");
	FILE *input;
	input  = fopen("classes_mod.csv", "r");
	int numlines = 0;
	char line [300];
	printf("in readfile");

	//checks if the file exists
	if ((input = fopen("classes_mod.csv", "r")) == NULL){
		printf("error opening file\n");
	}
	else{
		while(fgets(line,299,input) != NULL)
		{
			char *class_num, *name, *junk, *seats, *teach_name, *day, *time;
			class_num = strtok(line,",");
			strcpy(c->class_num, class_num);

			name = strtok(NULL,",");
			strcpy(c->name, name);

			junk = strtok(NULL, ",");
			seats = strtok(NULL, ",");
			c->seats = atoi(seats);

			junk = strtok(NULL, ",");
			junk = strtok(NULL, ",");
			teach_name = strtok(NULL, ",");
			strcpy(c->teach_name,teach_name);

			junk = strtok(NULL, ",");
			junk = strtok(NULL, ",");
			junk = strtok(NULL, ",");
			junk = strtok(NULL, ",");
			day = strtok(NULL, " ");
			strcpy(c->day, day);

			time = strtok(NULL, ",");
			strcpy(c->time, time);

			numlines ++;
		}
	}
	fclose(input);
	return numlines;
}
