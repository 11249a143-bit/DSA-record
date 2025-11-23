🧭 Aim:
  To write a C program that performs Binary Search on a sorted array to find the position of a given element.
⚙️ Algorithm:
  • Divide the search space into two halves by finding the middle index "mid".
  • Compare the middle element of the search space with the key.
  • If the key is found at middle element, the process is terminated.
  • If the key is not found at middle element, choose which half will be used as the next
  search space.
  – If the key is smaller than the middle element, then the left side is used for next
  search.
  – If the key is larger than the middle element, then the right side is used for next
  search.
  • This process is continued until the key is found or the total search space is exhausted.   
code:
#include <stdio.h>
// Function to perform Binary Search
int binary_search(int arr[], int size, int term) {
    int left = 0;               // Start index
    int right = size - 1;       // End index
// Continue searching while left index is less than or equal to right
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Find middle index safely
     if (arr[mid] == term)                 // If element found
            return mid;                       // Return its index
        else if (arr[mid] < term)             // If element is in right half
            left = mid + 1;
        else                                  // If element is in left half
            right = mid - 1;
    }
    return -1;                                // Element not found
}
int main() {
    int size, term;
    printf("Enter size of array: ");          
    scanf("%d", &size);
    int arr[size];                            // Declare array
    printf("Enter %d sorted numbers:\n", size);
    for (int i = 0; i < size; i++) {          // Input sorted numbers
        scanf("%d", &arr[i]);
    }
     printf("Enter number to search: ");       // Input search element
    scanf("%d", &term);

    int result = binary_search(arr, size, term);  // Call search function

    if (result != -1)                         
        printf("Found at index %d\n", result);
    else                                      
        printf("Not found\n");

    return 0;  
}


