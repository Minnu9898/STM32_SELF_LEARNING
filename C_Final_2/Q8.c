// 8. Write a C program that uses functions to convert a decimal number to any base between 2 and 16.
// Description: The program should prompt the user to enter a decimal number and a target base. A separate function must be written that performs the repeated division method, stores each remainder, and builds the result in the correct order. For bases above 9, remainders 10–15 should be represented as letters A–F. The converted value should be displayed from the main function. Pre-requisites: Functions, Loops, Arrays, Character Handling.




#include <stdio.h>

void Conversion (int a,int base)
{
     char result[50];
    int i=0, r;
    while (a > 0)
    {
        r = a % base;

        if (r < 10)
            result[i] = r + '0';
        else
            result[i] = r - 10 + 'A';

        a = a / base;
        i++;
    }
     // Print in reverse order
    printf("Converted value: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", result[j]);
    }
    printf("\n");
}
int main()
{
	int n,base;
	printf("Hello ! \n Enter a positive number: \n ");
	scanf("%d",&n);
	printf("Enter target base (2 and 16): ");
	scanf("%d", &base);

	Conversion(n,base);

}
