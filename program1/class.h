// charlie melnarik
// class.h
// 11/18/19

#include <stdio.h>
//#include "read.c"
//typedef struct class 
#ifndef CLASS_H_
#define CLASS_H_

typedef struct 
{
	char name[100];
	char class_num[15];
	char teach_name[100];
	int seats;
	char day [10];
	char time [10];
} class_t;

//all of the methods used
void printnum(class_t* ,int);
void printday(class_t* , int);
void PrintOneClass(class_t);
void printteach(class_t* ,int);
#endif
