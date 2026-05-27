// 23. Write a C program that rotates the elements of an array by n positions in a specified direction.
// Description: The program should prompt the user to enter the array elements, the number of positions (n) to rotate, and the direction (left or right). It must then shift the elements accordingly — elements that fall off one end should reappear at the opposite end. The rotation must work for any value of n, including values larger than the array size. The final rotated array should be displayed on the screen. Pre-requisites: Arrays, Loops, Modulus Operator.

#include <stdio.h>

int main()
{
    int arr[100], temp[100];
    int n, size, i;
    char dir;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter elements:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of rotations: ");
    scanf("%d", &n);

    printf("Enter direction (L for left, R for right): ");
    scanf(" %c", &dir);

    // Handle n greater than size
    n = n % size;

    if (dir == 'L' || dir == 'l')
    {
        // Left rotation
        for (i = 0; i < size; i++)
        {
            temp[i] = arr[(i + n) % size];
        }
    }
    else if (dir == 'R' || dir == 'r')
    {
        // Right rotation
        for (i = 0; i < size; i++)
        {
            temp[i] = arr[(i - n + size) % size];
        }
    }
    else
    {
        printf("Invalid direction!\n");
        return 0;
    }

    printf("Rotated array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", temp[i]);
    }

    return 0;
}
