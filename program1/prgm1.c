// program 1 
// charlie melnarik
// 11/18/19

#include <stdio.h>
#include <stdlib.h>
#include "class.h"



// prints one single class
void PrintOneClass(class_t c)
{
        printf("%s %s %s %d %s %s", c.name, c.class_num, c.teach_name, c.seats, c.day, c.time);
}
// prints the classes by number
void printnum(class_t* c, int size)
{
	char answer[20];
	char nl;
	printf("Enter class number");
	scanf("%[^\n]", answer, &nl);

	for (int i = 0; i < size; i++)
	{
	if(strcmp(answer, c[i].class_num) == 0)
		{
			PrintOneClass(c[i]);
		}
	}
}
//prints the class by teacher
void printteach(class_t* c, int size)
{
	char teacher[80];
	printf("Enter teacher last name");
	scanf("%s", teacher);
	
	for (int i = 0; i < size; i++)
	{
		if (strcmp(c[i].teach_name, teacher) == 0)
		{
			PrintOneClass(c[i]);
		}
	}
}
//prints the classes by the day of the week
void printday(class_t* c, int size)
{
	char day[10];
	char nl;
	while (1){
		printf("Enter class days to print MWF or TR");
		scanf("%s", day);
		scanf("%c", &nl);
	
		if (strcmp(day, "MWF")!= 0 && strcmp(day, "TR") != 0)
		{
			printf("Error, bad day input %s\n", day);
			continue;
		}
		printf("List of classes for days %s\n", day);
		for (int i = 0; i < size; i++)
		{
			if (strcmp(c[i].day, day) == 0)
			{
				PrintOneClass(c[i]);
			}
		}
		break;
	}
}

// main function runs the querey and executes the above functions
int main (void){

	printf("test");
	class_t cl[300];
	int size = readfile(cl);
	printf("read file executed");	

	int num;

	//querey
	while (1){
		printf("1) Print a class given a CSCI number \n");
		printf("2) Print all classes available on MWF or TR \n");
		printf("3) Print all classes by a given professors name \n");
		printf("4) Quit \n ");
		printf("Enter your choice: ");
		scanf("%d",&num);

		if (num == 4)
		{
			break;
		}

		if (num > 3 || num < 0)
		{
			printf("Invalid Number, try again: \n");
			continue;
		}
		if (num ==1)
		{
			printnum(cl,size);
		}
		if (num == 2)
		{
			printteach(cl, size);
		}
		if (num == 3)
		{
			printday(cl, size);
		}


	
	}
	return (0);
}

