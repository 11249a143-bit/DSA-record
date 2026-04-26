*/Aim:
To implement a randomized version of the Quick Sort algorithm by selecting a random pivot element, thereby improving the average-case performance during sorting.*/
//program//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to swap two values */
void exchange(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* partition function using last element as pivot */
int doPartition(int arr[], int start, int end)
{
    int pivot = arr[end];   // pivot element
    int i = start - 1;      // index for smaller element

    for (int j = start; j < end; j++)
    {
        // place elements smaller than pivot to the left
        if (arr[j] < pivot)
        {
            i++;
            exchange(&arr[i], &arr[j]);
        }
    }

    // place pivot in correct sorted position
    exchange(&arr[i + 1], &arr[end]);

    return i + 1;
}

/* randomized quicksort function */
void randomizedQuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        // generate a random index within range
        int randPos = start + rand() % (end - start + 1);

        // move random element to end to use as pivot
        exchange(&arr[randPos], &arr[end]);

        // partition the array
        int pivotIndex = doPartition(arr, start, end);

        // recursively sort left and right parts
        randomizedQuickSort(arr, start, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, end);
    }
}

int main()
{
    int n;

    srand(time(NULL));  // seed for randomness

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Enter a valid positive number.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // calling randomized quicksort
    randomizedQuickSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
