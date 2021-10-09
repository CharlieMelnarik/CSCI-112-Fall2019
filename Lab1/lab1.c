#include <stdio.h>

// lab1 Charlie Melnarik
// 9/10/19

int main()

{
	//sets up the input variables
	float a,b;

	//prints what the user sees 
	printf("Enter beginning odometer reading =>");

	//inputs the number the user enters
	scanf("%f",&a);

	printf("\nEnter ending odometer reading =>");
	scanf("%f", &b);

	// outputs the answer miles traveled and the reimbursement
	printf("\nYou traveled %.1f",b-a); printf(" miles");
	printf("\nAt $.35 a mile, your reimbursement is $%.2f", (b-a)*.35); printf(".");
	printf("\n");

	//finishes program
	return(0);
}

