                                                //QUICK SORT//

//Aim : To sort a list of elements using the Quick Sort algorithm//

🧭 Algorithm:

BEGIN
🔷 1. Swap(a, b)
Store value of *a in temp.
Assign *b to *a.
Assign temp to *b.
(Used to interchange values during partitioning.)
🔷 2. Partition(list, low, high)
Choose pivot as the element at list[high].
Set i = low - 1.
For j = low to high - 1, repeat:
a. If list[j] < pivot:
Increment i.
Swap list[i] and list[j].
After loop ends → swap pivot into correct position:
Swap list[i + 1] and list[high].
Return the pivot index i + 1.
🔷 3. QuickSort(list, low, high)
If low < high:
a. Call partition() to get pivot index pi.
b. Recursively sort left sub-array → quickSort(list, low, pi - 1).
c. Recursively sort right sub-array → quickSort(list, pi + 1, high).
🔷 4. Main Program
Read number of elements n.
Read array elements into list[n].
Call quickSort(list, 0, n - 1).
Print the sorted array.
End program.

🧭 Code:

#include <stdio.h>

//Swap the numbers / Call by referene to persist changes
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition 
int partition(int list[], int low, int high)
{
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i + 1], &list[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    quickSort(list, 0, n - 1);

    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);

    return 0;
}
