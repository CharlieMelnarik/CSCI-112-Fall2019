// Charlie Melnarik
// Lab 6 
// 10/31/19

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* fact_calc(int n, char*str)
{

	// sets up buffer. adds the factorial and equals to the str
	char buffer[sizeof(int)];
	snprintf(buffer, sizeof(buffer), "%d", n);
	strcat(str, buffer);
	strcat(str, "! = ");

	// calculates the factorial answer and stores and concatinates the 
	// numbers i into the str
	// also the equals if at the end
	int x = 1;
	for (int i = n; i > 0; i--)
	{
		x *= i;
		snprintf(buffer, sizeof(buffer), "%d", i);
		strcat(str, buffer);
		if (i != 1){
		strcat(str, " x ");
		}
		else {
		strcat(str, " = ");
		}
		
	}
	//adds the asnwer to the str and returns the str to be used in main
	snprintf(buffer, sizeof(buffer), "%d",x);
	strcat(str, buffer);
	return str;
}

int main (void)
{
        int num;

        //prepare by creating the string with malloc

        //use a preset string of all $'s (80)

        char* len_ds = malloc(sizeof(char)*81);
        char* mult_string = malloc(sizeof(char)*81);
        char* ds = "*********************************************************************************************************";
        //until done

        while (1)
        {



        //read in the two integers

		
                printf("Enter an integer between  0 to 9 or -1 to quit; ");
                scanf("%d", &num);

                if (num == -1)
                {
                        break;
                
		}

		if (num > 9 || num <0)
		{
			printf("invalid number \n");
			continue;
		}

        //prepare teh string by filling it with \0s

                memset(mult_string,'\0', 80);
                memset(len_ds,'\0', 80);
        //create my multiplication string

               mult_string = fact_calc(num, mult_string);

        //build the right size * string

                strncpy(len_ds, ds, strlen(mult_string)+4);
        //print my strings

                printf("%s\n* %s *\n%s\n", len_ds, mult_string, len_ds);

        }
        return (0);
}
