// lab 3
// Charlie Melnarik
// 9/24/19
// interest
#include <stdio.h>
#include <math.h>
void calculate (){


	double principal;
	double interest;
	double payments;
	double payment;
	
	 printf("enter principal");
        scanf("%lf", principal);
	printf("\n");

	printf("enter interest");
	scanf("%lf", interest);
	printf("\n");

	printf("enter amount of payments");
	scanf("%lf", payments);
	printf("\n");


	double monthly_interest;
	int num = 0;

	monthly_interest =((1/12)*interest);

	for (int i = 0; i < 6; i++){
		printf(" %d \t\t\t\t " ,num);
		num++;
		 payment = (interest*principal)/(1-pow(1+interest,(-payments)));
	 	printf("%.2lf\t\t\t %.2lf\t\t\t",monthly_interest, payment);
       	 	printf("\n");
	}



}


int main(void){
	
	int num = 0;	

	printf("\n");
	printf("Payment Ballance\t\t Interest\t\t Principal\t\t principal");
	printf("\n");
	calculate();

}
