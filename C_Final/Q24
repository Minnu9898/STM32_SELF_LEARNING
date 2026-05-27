// 24. Write a C program that merges two sorted arrays into a single sorted array without using any sorting function.
// Description: The program should prompt the user to enter the sizes and elements of two arrays, each already sorted in ascending order. It must then merge them into a third array by comparing elements from both arrays one by one and placing the smaller element first, continuing until all elements are placed. The final merged sorted array should be displayed on the screen. Pre-requisites: Arrays, Loops, Multiple Array Handling.

#include <stdio.h>

int main()
{
    int a[100], b[100], c[200];
    int n1, n2, i, j, k;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first array (sorted):\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second array (sorted):\n");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }

    i = 0; // index for a
    j = 0; // index for b
    k = 0; // index for c

    // Merge arrays
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }

    // Copy remaining elements
    while (i < n1)
    {
        c[k++] = a[i++];
    }

    while (j < n2)
    {
        c[k++] = b[j++];
    }

    // Display merged array
    printf("Merged sorted array:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}
