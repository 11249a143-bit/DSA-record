/*
Aim:
To solve the Tower of Hanoi problem using recursion and display
the sequence of moves required to transfer all disks from source
to destination.
*/

#include <stdio.h>

// Recursive function for Tower of Hanoi
void solveTOH(int disks, char source, char auxiliary, char destination)
{
    // Base case: only one disk
    if (disks == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary
    solveTOH(disks - 1, source, destination, auxiliary);

    // Step 2: Move the largest disk to destination
    printf("Move disk %d from %c to %c\n", disks, source, destination);

    // Step 3: Move n-1 disks from auxiliary to destination
    solveTOH(disks - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0)
    {
        printf("Invalid input. Enter a positive number.\n");
        return 1;
    }

    printf("\nSequence of moves:\n");

    solveTOH(n, 'S', 'A', 'D');

    return 0;
}
