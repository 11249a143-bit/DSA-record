/*
Aim:
To implement the Best Fit algorithm for bin packing, where each item
is placed into the bin that leaves the minimum unused space.
*/

#include <stdio.h>

// Function to perform Best Fit allocation
void applyBestFit(int weights[], int totalItems, int maxCapacity)
{
    printf("\n--- Best Fit Bin Packing ---\n");

    int remainingSpace[totalItems];   // Stores remaining capacity of bins
    int binsUsed = 0;

    // Initialize all bins with full capacity
    for (int i = 0; i < totalItems; i++)
    {
        remainingSpace[i] = maxCapacity;
    }

    // Loop through each item
    for (int i = 0; i < totalItems; i++)
    {
        int selectedBin = -1;
        int leastSpaceLeft = maxCapacity + 1;

        // Find the best bin for current item
        for (int j = 0; j < binsUsed; j++)
        {
            int spaceAfterPlacing = remainingSpace[j] - weights[i];

            if (spaceAfterPlacing >= 0 && spaceAfterPlacing < leastSpaceLeft)
            {
                selectedBin = j;
                leastSpaceLeft = spaceAfterPlacing;
            }
        }

        // If a suitable bin is found
        if (selectedBin != -1)
        {
            remainingSpace[selectedBin] -= weights[i];
            printf("Item %d (size %d) -> Bin %d\n",
                   i + 1, weights[i], selectedBin + 1);
        }
        else
        {
            // Create a new bin
            remainingSpace[binsUsed] = maxCapacity - weights[i];
            printf("Item %d (size %d) -> Bin %d\n",
                   i + 1, weights[i], binsUsed + 1);
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

        // Check if item size exceeds capacity
        if (items[i] > capacity)
        {
            printf("Invalid! Item exceeds bin capacity. Re-enter.\n");
            i--; // repeat input for same item
        }
    }

    applyBestFit(items, n, capacity);

    return 0;
}
