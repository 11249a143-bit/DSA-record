/*
Aim:
To generate the Fibonacci series up to 'n' terms and display
the nth Fibonacci number.
*/

#include <stdio.h>

int main()
{
    int n;
    int first = 0, second = 1, next;

    printf("Enter the number of terms (n): ");

    // Input validation
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    printf("Fibonacci Series: ");

    // Print first term
    if (n >= 1)
        printf("%d ", first);

    // Print second term
    if (n >= 2)
        printf("%d ", second);

    // Generate remaining terms
    for (int i = 3; i <= n; i++)
    {
        next = first + second;
        printf("%d ", next);

        // Update values
        first = second;
        second = next;
    }

    // Display nth term
    if (n == 1)
        printf("\nFibonacci term %d = %d\n", n, first);
    else
        printf("\nFibonacci term %d = %d\n", n, second);

    return 0;
}
