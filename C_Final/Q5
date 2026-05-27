// 5. Write a C program that uses a function to check whether a given number is a Perfect Number.

// Description: The program should prompt the user to enter a positive integer. A separate function must be written that computes the sum of all proper divisors of the number (excluding the number itself) and returns whether the sum equals the original number. The main function should display whether the number is perfect or not. (Example: 6 = 1+2+3, 28 = 1+2+4+7+14) Pre-requisites: Functions, Loops, Return Values.



#include <stdio.h>

void Perfect (int a)
{
    int sum=0;
   if(a<0)
   {
       printf("Enter a positive number");
   }
   else
   {
       for(int i=1;i<=a/2;i++)
       {
          if(a%i==0) 
          {
              sum+=i;
          }
       }
       
   }
   if(sum==a)
   {
       printf("Enterd num is a PERFECT num");
   }
   else
   {
       printf("Enterd num is a Not A PERFECT num");
   }
   
   
}
int main()
{
	int n;
	printf("Hello ! \n Enter a number: \n ");
	scanf("%d",&n);
	Perfect(n);

	return 0;
}

