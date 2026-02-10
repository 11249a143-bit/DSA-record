                                             //LINEAR SEARCH//                                 

🎯 Aim:
     To find a given number in a list using the Linear Search method, checking each element one by one.
Algorithm:
    Step 1: start from index 0 and compare each element with target.
    Step 2: if arr[i] is not equal to target, increment i.
    Step 3: Continue until you find arr[i] equals the target.
    Step 4: Return the index i where the target is found.
    Step 5: If end is reached and target is not found return -1.
code:
    #include <stdio.h>

int linear_search(int arr[], int size, int term) {
    // Traverse the array to find the search term
    for (int i = 0; i < size; i++) {
        // If the element matches the search term, return its index
        if (arr[i] == term)
            return i; 
    }
    // Return -1 if the term is not found
    return -1; 
}

int main() {
    int size, term;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &term);

    // Call the linear search function and store result
    int result = linear_search(arr, size, term);
    
    // Display the result based on whether the number was found or not
    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}
