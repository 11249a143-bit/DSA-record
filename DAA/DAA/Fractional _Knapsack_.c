Aim

To implement the Fractional Knapsack problem using greedy method.


program


#include <stdio.h>

// Step 1: Define structure for items
struct Item
{
    int weight;
    int value;
    float ratio;
};

// Step 2: Function to sort items based on ratio
void sortItems(struct Item arr[], int n)
{
    struct Item temp;

    // Step 3: Apply bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Step 4: Compare ratios
            if (arr[j].ratio < arr[j + 1].ratio)
            {
                // Step 5: Swap items
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    float capacity;

    // Step 6: Read number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Step 7: Validate input
    if (n <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    struct Item arr[n];

    // Step 8: Input weight and value
    printf("Enter weight and value for each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d\n", i + 1);

        printf("Weight: ");
        scanf("%d", &arr[i].weight);

        printf("Value: ");
        scanf("%d", &arr[i].value);

        // Step 9: Calculate ratio
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    // Step 10: Read knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Step 11: Sort items by ratio
    sortItems(arr, n);

    float maxProfit = 0.0;

    // Step 12: Apply greedy selection
    for (int i = 0; i < n; i++)
    {
        if (capacity >= arr[i].weight)
        {
            // Step 13: Take full item
            maxProfit += arr[i].value;
            capacity -= arr[i].weight;
        }
        else
        {
            // Step 14: Take fractional part
            maxProfit += arr[i].ratio * capacity;
            break;
        }
    }

    // Step 15: Display result
    printf("Maximum Profit = %.2f\n", maxProfit);

    // Step 16: Stop program
    return 0;
}
