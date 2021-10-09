// charlie Melnarik 
// lab 2
// 9/13/19

#include <stdio.h>


// first function computes the quadrant from the coordinates
int ComputeQuadNumber (x, y){
	
	if (x<0 && y<0){
		return 3;
		}
	else if (x<0 && y>0){
		return 2;
	}
	else if (x>0 && y>0){
		return 1;
	}
	else if (x>0 && y<0) {return 4;}

	else if (x == 0 && y == 0) {return 5;}

	else if (x!=0 && y==0){return 6;}

	else {return 7;}


}
// second function determines if the coordinates are at the center or
// on the axisi
char* ProduceAxisString (int ComputeQuadNumber){
        if(ComputeQuadNumber == 5){return ( "at the center");}
        else if (ComputeQuadNumber == 6){return ( "on the x-axis");}
	else {return ( "on the y-axis");}
}
// third function computes the first function and creates the output
char* ProduceQuadString (int ComputeQuadNumber){
	if(ComputeQuadNumber == 1){
		return ("I");
	}
	else if (ComputeQuadNumber == 2){
		return("II");
	}
	else if (ComputeQuadNumber == 3){
		return ("III");
	}
	else if (ComputeQuadNumber == 4)  {return ("IV");}
	
	else {return ProduceAxisString(ComputeQuadNumber);}

}
// main  takes input and outputs answer
int main (void){
double x, y;

printf("enter  values => ");
scanf("%lf %lf" , &x, &y);
int m= ComputeQuadNumber(x,y);
printf("\n");
printf("%.1lf, %.1lf ", x, y); printf(" is on "); printf(ProduceQuadString(m));
printf("\n");

return (0);
}
