// Charlie Melnarik
// 10/21/19
// csci 112
// lab 5

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void polygon_area(double *x,double *y, int n);
int  output_corners(double *x,double *y);

int get_corners(double *x,double *y)
{
//sets up the variables
//reads the file and adds it to arrays
int counter = 0;
char buffer[100];
while
(fgets (buffer, 100, stdin) != NULL){
        char *end_of_first_double;
        double first = strtod(buffer,&end_of_first_double);
        x[counter] = first;
        printf("%.2lf ",first);
        double second = strtod(end_of_first_double,NULL);
        y[counter] = second;
        printf("%.2lf\n",second);
        counter ++;

}
//returns counter to use in the area calculation for n
return counter;
}
//prints the table fromt the file
int output_corners(double *x,double *y)
{
        printf("x    y\n");
        int counter = get_corners(x,y);
        return counter;
}
// calculates the area of the polygon
void polygon_area(double *x,double *y, int n)
{
        double area = 0;
        for (int i = 0; i < n-2; i++){
                area += ((x[i+1]+x[i]) *( y[i+1]-y[i]));
        }
        area = (double)abs(area)*.5;
        printf("The area is %0.2lf",area);
        printf("\n");
}
// runs the functions and produces the calculated area output
int main ()
{
        double x[100];
        double y[100];
        int n = output_corners(x,y);
        polygon_area(x,y,n);
        return (0);
}
