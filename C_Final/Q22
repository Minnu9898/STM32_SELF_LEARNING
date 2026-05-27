// 22. Write a C program that uses an array to find the second largest and second smallest element in a list of numbers.
// Description: The program should prompt the user to enter the size of the array and its elements. It must then scan through the array and determine both the second largest and second smallest values without sorting the array. The program should handle duplicate values correctly — if all elements are the same, it should display an appropriate message. Both results should be displayed on the screen. Pre-requisites: Arrays, Loops, Conditional Statements.

#include <stdio.h>
#include <limits.h>

int main()
{
    int arr[100], n, i;
    int min = INT_MAX, secondMin = INT_MAX;
    int max = INT_MIN, secondMax = INT_MIN;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Find min, second min, max, second max
    for (i = 0; i < n; i++)
    {
        // For smallest
        if (arr[i] < min)
        {
            secondMin = min;
            min = arr[i];
        }
        else if (arr[i] > min && arr[i] < secondMin)
        {
            secondMin = arr[i];
        }

        // For largest
        if (arr[i] > max)
        {
            secondMax = max;
            max = arr[i];
        }
        else if (arr[i] < max && arr[i] > secondMax)
        {
            secondMax = arr[i];
        }
    }

    // Check results
    if (secondMin == INT_MAX || secondMax == INT_MIN)
    {
        printf("No distinct second smallest or second largest element found.\n");
    }
    else
    {
        printf("Second Smallest = %d\n", secondMin);
        printf("Second Largest = %d\n", secondMax);
    }

    return 0;
}

