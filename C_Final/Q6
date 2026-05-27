// 6. Write a C program that uses a recursive function to find the GCD of two numbers using the Euclidean algorithm.

// Description: The program should prompt the user to enter two positive integers. A recursive function must be written that repeatedly applies the Euclidean method replacing the larger number with the remainder of dividing the two until the remainder is zero. The GCD should be returned to the main function and displayed on the screen. Pre-requisites: Functions, Recursion, Modulus Operator.



#include <stdio.h>

int GCD (int num1,int num2)
{
   
   if (num2==0)
    {
        return num1;
    }
    else
    {
        return GCD(num2,num1%num2);
    }
}
int main()
{
	int n1,n2,Output;
	printf("Hello ! \n Enter 2 positive number: \n ");
	scanf("%d%d",&n1,&n2);
	if (n1 <= 0 || n2 <= 0)
    {
        printf("Please enter positive integers only.\n");
    }
	Output= GCD(n1,n2);
    printf("GCD of %d,%d is %d",n1,n2,Output);

}

