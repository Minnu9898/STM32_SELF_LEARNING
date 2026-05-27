// 15. Write a C program that takes a string from the user and replaces every sequence of multiple consecutive spaces with a single space.
// Description: The program should prompt the user to enter a sentence that may contain several spaces between words. It must then process the string to ensure that any instance where two or more blank spaces appear together is reduced to just one blank space. The final cleaned string should be displayed on the screen. Pre-requisites: Loops, Strings, Conditional Statements, ASCII, Operators

#include <stdio.h>

int main()
{
    char str[200], result[200];
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        // Copy non-space characters
        if (str[i] != ' ')
        {
            result[j++] = str[i];
        }
        else
        {
            // Copy only one space
            result[j++] = ' ';

            // Skip all extra spaces
            while (str[i] == ' ')
            {
                i++;
            }
            continue;
        }
        i++;
    }

    result[j] = '\0';

    printf("Cleaned string:\n%s\n", result);

    return 0;
}
