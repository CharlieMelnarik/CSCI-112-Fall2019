// charlie melnarik
// lab4
// csci 112
// 10/14/19

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// compute function to do the adding x[i] and y[i] to create the z array using pointers
double ComputeZ(int *x, int *y, int *z)
{
	// does the math
	for (int i = 0; i < 10; i++)
	{
		*(z + i ) = *(x + i ) + *(y + i );
	}
	
	//finds the sum of the z array as well as the square root of the sum
	//and also prints them
	int ztotal =0;
	for (int i = 0; i < 10; i++)
	{
		ztotal += *(z + i);
	}
	double zroot = sqrt(ztotal);

	printf("\ntotal of z added up %d\n\n", ztotal);

	printf("square root %.3f\n\n", zroot);
}
//print table function prints all of the arrays 
//in a line
void PrintTable(int *x,int *y,int *z)
{
	for (int i = 0; i < 10; i++)
        {
                printf("%d\t x = %d\t y = %d\t z =%d\t\n",i+1, *(x + i), *(y + i), *(z + i ));
        }
}
// main creates x and y arrays and calls the two previous functions
int main()
{
	int x[9] = {0} ;

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		x[i] = (rand()%100);
	}


/////////////////////////////////////////////////
	 int y[9] = {0} ;

        for (int i = 0; i < 10; i++)
        {
                y[i] = (rand()%100);
        }

	int z[9] = {0};
	ComputeZ(x, y, z);
	PrintTable(x,y,z);

	return(0);
}

