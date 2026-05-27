// 18. Write a C program that takes an integer from the user and extracts (n) bits starting from a specific bit position.
// Description: The program should prompt the user to enter a number, a starting position, and the number of bits to be retrieved. It must then isolate that specific sequence of bits from the original value and display the resulting number on the screen. The other bits in the number should not affect the final output. Pre-requisites: Bitwise Operators.


#include <stdio.h>

// Function to extract n bits from position pos
int extractBits(int num, int pos, int n)
{
    // Shift right to bring desired bits to LSB
    num = num >> pos;

    // Create mask with n 1's
    int mask = (1 << n) - 1;

    // Apply mask
    return num & mask;
}

int main()
{
    int num, pos, n, result;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter starting bit position (0-based): ");
    scanf("%d", &pos);

    printf("Enter number of bits to extract: ");
    scanf("%d", &n);

    result = extractBits(num, pos, n);

    printf("Extracted value = %d\n", result);

    return 0;
}

