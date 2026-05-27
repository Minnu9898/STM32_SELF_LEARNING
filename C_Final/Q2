// 2. Write a C program that asks the user to enter a number and determines whether that number is prime or not.
// Description: A prime number is a natural number greater than 1 that cannot be formed by multiplying two smaller natural numbers. In simpler terms, it is a number that is only divisible by 1 and itself. Your program should take an integer as input and check if it has any divisors other than 1 and the number itself. If the user enters a number like 2, 3, or 5, the program should identify it as prime. However, if the user enters a number less than 2, or a number like 4 or 6 that can be divided by other values, the program should state it is not prime. You should use a simple loop to test for these divisors and a conditional statement to print the final result. Pre-requisites: Loops, Conditional Statements, Operators



#include <stdio.h>

void prime(int a)
{
	if (a<2)
	{
        printf("Not a Prime Number\n");
	}
	else 
	{
	     int i;
	     for (i=2;i<=a;i++)
	     {
	         if (a%i==0)
	         {
	            printf("Entered number is not a prime \n"); 
	            break;
	         }
	         else
	         {
	             printf("Entered number is  a prime number");
	             break;
	         }
	             
	     }
	}
}
int main()
{
	int n;
	printf("Hello ! \n Enter a number: \n ");
	scanf("%d",&n);
	prime(n);

	return 0;
}

