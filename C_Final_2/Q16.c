// 16. Write a C program that takes a string from the user and converts all uppercase letters into their corresponding lowercase letters.
// Description: The program should prompt the user to enter a sequence of characters. It must then check each character individually. If a character is an uppercase letter, the program should convert it to its lowercase equivalent. If the character is already lowercase or is not a letter at all, the program should leave it exactly as it is. The final modified string should be displayed on the screen. Pre-requisites: Loops, Strings, Conditional Statements, ACII.

#include <stdio.h>

int main()
{
    char str[200];
    int i = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Traverse each character
    while (str[i] != '\0')
    {
        // Check if uppercase
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;  // convert to lowercase
        }
        i++;
    }

    printf("Modified string:\n%s", str);

    return 0;
}


