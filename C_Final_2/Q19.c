// 19. Write a C program that takes a number and replaces n of its bits, starting from a given position, with another set of n bits from a second number.
// Description: The program should prompt the user to enter two integers, a starting bit position, and the number of bits n to be modified. It must then clear $n$ bits in the first number at the specified position and replace them with the corresponding $n$ bits from the second number. The final resulting value should be displayed on the screen while all other bits in the first number remain unchanged. Pre-requisites: Bitwise Operators

#include <stdio.h>

// Function to replace bits
int replaceBits(int num1, int num2, int pos, int n)
{
    // Step 1: Create mask with n 1's
    int mask = (1 << n) - 1;

    // Step 2: Extract n bits from num2
    int bits = num2 & mask;

    // Step 3: Shift extracted bits to correct position
    bits = bits << pos;

    // Step 4: Clear n bits in num1 at position pos
    int clearMask = ~(mask << pos);
    num1 = num1 & clearMask;

    // Step 5: Insert bits into num1
    return num1 | bits;
}

int main()
{
    int num1, num2, pos, n, result;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter starting position (0-based): ");
    scanf("%d", &pos);

    printf("Enter number of bits (n): ");
    scanf("%d", &n);

    result = replaceBits(num1, num2, pos, n);

    printf("Result after replacement = %d\n", result);

    return 0;
}

