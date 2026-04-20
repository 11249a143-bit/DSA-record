/*
Aim:
To implement the First Fit algorithm for bin packing, where each item
is placed in the first available bin that has enough space.
*/

#include <stdio.h>

// Function to apply First Fit strategy
void applyFirstFit(int sizes[], int totalItems, int maxCapacity)
{
    int remaining[totalItems];   // Stores remaining space in each bin
    int binsUsed = 0;

    // Initialize all bins with full capacity
    for (int i = 0; i < totalItems; i++)
    {
        remaining[i] = maxCapacity;
    }

    // Traverse through each item
    for (int i = 0; i < totalItems; i++)
    {
        int isPlaced = 0;

        // Try placing item in existing bins
        for (int j = 0; j < binsUsed; j++)
        {
            if (remaining[j] >= sizes[i])
            {
                remaining[j] -= sizes[i];
                printf("Item %d (size %d) -> Bin %d\n",
                       i + 1, sizes[i], j + 1);
                isPlaced = 1;
                break;
            }
        }

        // If item cannot fit in any existing bin, create new bin
        if (!isPlaced)
        {
            remaining[binsUsed] = maxCapacity - sizes[i];
            printf("Item %d (size %d) -> Bin %d\n",
                   i + 1, sizes[i], binsUsed + 1);
            binsUsed++;
        }
    }

    printf("Total bins required: %d\n", binsUsed);
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);

        // Validate input
        if (items[i] > capacity)
        {
            printf("Invalid! Item exceeds bin capacity. Re-enter.\n");
            i--; // retry same item
        }
    }

    applyFirstFit(items, n, capacity);

    return 0;
}
