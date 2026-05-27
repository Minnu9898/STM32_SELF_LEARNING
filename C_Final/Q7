// 7. Write a C program that uses a function to count the frequency of each digit (0–9) in a given integer.
// Description: The program should prompt the user to enter an integer. A separate function must be written that takes the number, extracts each digit using a loop, and updates a frequency array accordingly. The function should not return a single value but instead update the array directly. The main function should then print how many times each digit appears in the number. Pre-requisites: Functions, Arrays, Loops, Pass by Reference (Pointers).



#include <stdio.h>

int Freq (int a,int f[])
{
    int digit;
    while(a>0)
    {
        digit=a%10; //last digit (if I enter 115- 0 2 0 0 1 0 0 0 0 0)
        f[digit]++;
        a=a/10;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("Digit %d: %d times\n", i, f[i]);
    }

}
int main()
{
	int n,freqarr[10]={0};
	printf("Hello ! \n Enter a positive number: \n ");
	scanf("%d",&n);

	Freq(n,freqarr);
    

}

