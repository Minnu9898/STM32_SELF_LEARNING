
// 14. Write a C program that takes a string input from the user and determines whether it is a pangram or not.
// Description: The program should prompt the user to enter a sentence or a string of characters. It must then verify if every letter of the alphabet from A to Z appears at least once within the provided text, regardless of whether the letters are uppercase or lowercase. The final output should state if the string is a pangram. Pre-requisites: Loops, Strings, Conditional Statements, ASCII, Operators

#include <stdio.h>

int main()
{
    char str[200];
    int i, index;
    int alphabet[26] = {0};  // to track A–Z

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Process each character
    for (i = 0; str[i] != '\0'; i++)
    {
        // Convert uppercase to lowercase
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            index = str[i] - 'A';
            alphabet[index] = 1;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            index = str[i] - 'a';
            alphabet[index] = 1;
        }
    }

    // Check if all letters are present
    for (i = 0; i < 26; i++)
    {
        if (alphabet[i] == 0)
        {
            printf("The string is NOT a pangram.\n");
            return 0;
        }
    }

    printf("The string is a pangram.\n");

    return 0;
}
