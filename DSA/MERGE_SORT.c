                                                  //MERGE SORT//

//Aim : To sort an array of elements using the Merge Sort algorithm based on Divide and Conquer technique.//

🧭 Algorithm:

BEGIN
🔷 1. merge(arr, left, mid, right)
(Merge two sorted subarrays)
Set i = left (start of left subarray).
Set j = mid + 1 (start of right subarray).
Set k = 0 (index of temporary array).
Create a temporary array temp[] to store merged elements.
While both subarrays have elements:
a. If arr[i] < arr[j], copy arr[i] to temp[k], increment i and k.
b. Else copy arr[j] to temp[k], increment j and k.

Copy remaining elements from left subarray (if any).

Copy remaining elements from right subarray (if any).
Copy all elements from temp[] back to the original array from index left to right.
🔷 2. mergeSort(arr, left, right)
If left < right:
a. Find middle index:
→ mid = (left + right) / 2
b. Recursively sort the left half:
→ mergeSort(arr, left, mid)
c. Recursively sort the right half:
→ mergeSort(arr, mid + 1, right)
d. Call merge() to merge the two sorted halves.
🔷 3. Main Program
Read number of elements n.
Read n elements into arr.
Call mergeSort(arr, 0, n - 1).
Print the sorted array.
End program.
END

  🧭 Code:

#include <stdio.h>

// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    // Merge logic
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy left-out elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy temp back to original
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);      // Left part
        mergeSort(arr, mid + 1, right); // Right part
        merge(arr, left, mid, right);   // Merge halves
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
