// 12. Write a C program that takes a string from the user and checks whether it is a palindrome.
// Description: The program should prompt the user to enter a string. It must determine if the string reads the same forward and backward. The program should then display a message to the user stating whether the input is a palindrome or not. Pre-requisites: Loops, Control Statements, Strings and Operators.

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, length, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);   
    length = strlen(str);

    // Compare characters from both ends
    for (i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("The string is a Palindrome.\n");
    else
        printf("The string is NOT a Palindrome.\n");

    return 0;
}

