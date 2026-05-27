// 3. Write a C program that takes a positive integer from the user and calculates its factorial.
// Description: The program should prompt the user to enter a single whole number. It must then calculate the factorial of that number, which is the product of all positive integers from 1 up to the number entered. The final result should be displayed clearly on the screen. The program should also account for the fact that the factorial of 0 is Pre-requisites: Operators, Data Types, Loops.



#include <stdio.h>

void factorial(int a)
{
    int i,fact=1;
	if (a<0)
	{
        printf(" Negative num not Valid");
	}
	else 
	{
	     
	     for (i=1;i<=a;i++)
	     {
	         fact=fact*i;
	     }
	}
	printf("Factorial of number %d is %d", a,fact);
}
int main()
{
	int n;
	printf("Hello ! \n Enter a number: \n ");
	scanf("%d",&n);
	factorial(n);

	return 0;
}


