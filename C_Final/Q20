// 20. Write a C program that takes two integers and swaps n bits starting from a given position in both numbers.
// Description: The program should prompt the user to enter two integers, a starting bit position, and the number of bits (n) to be swapped. It must then exchange the n consecutive bits at the specified position between the two numbers — the bits from the first number go into the second, and vice versa — while all remaining bits in both numbers stay exactly as they were. Both final values should be displayed on the screen after the swap. Pre-requisites: Bitwise Operators, Loops, Assignment Operators.
// \

#include <stdio.h>

// Function to swap n bits at position pos
void swapBits(int *a, int *b, int pos, int n)
{
    // Step 1: Create mask of n bits
    int mask = (1 << n) - 1;

    // Step 2: Extract bits from both numbers
    int bitsA = (*a >> pos) & mask;
    int bitsB = (*b >> pos) & mask;

    // Step 3: Find differing bits
    int xorBits = bitsA ^ bitsB;

    // Step 4: Shift back to position
    xorBits = xorBits << pos;

    // Step 5: Swap using XOR
    *a = *a ^ xorBits;
    *b = *b ^ xorBits;
}

int main()
{
    int num1, num2, pos, n;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter starting position (0-based): ");
    scanf("%d", &pos);

    printf("Enter number of bits (n): ");
    scanf("%d", &n);

    swapBits(&num1, &num2, pos, n);

    printf("After swapping:\n");
    printf("First number = %d\n", num1);
    printf("Second number = %d\n", num2);

    return 0;
}

