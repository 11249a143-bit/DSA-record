/*
Aim:
To implement the Fractional Knapsack problem using a greedy approach
to maximize profit based on value-to-weight ratio.
*/

#include <stdio.h>

// Structure to store item details
struct Product
{
    int weight;
    int value;
    float ratio; // value per unit weight
};

// Function to sort items based on ratio (descending order)
void sortByRatio(struct Product arr[], int n)
{
    struct Product temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].ratio < arr[j + 1].ratio)
            {
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

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of items.\n");
        return 1;
    }

    struct Product items[n];

    printf("Enter weight and value of each item:\n");

    // Input item details
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate value-to-weight ratio
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items based on ratio
    sortByRatio(items, n);

    float maxProfit = 0.0;

    // Apply greedy selection
    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            // Take full item
            maxProfit += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            // Take fractional part
            maxProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", maxProfit);

    return 0;
}
