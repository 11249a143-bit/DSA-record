                                                  //STACK//

//*Aim: To find the position of a given number in a sorted list using the Binary Search method efficiently.*//
ALGORITHM:
 PUSH Operation:
Step 1: Check if TOP == MAX - 1.
Step 2: If true, display "Stack Overflow".
Step 3: Else increment TOP by 1.
Step 4: Set stack[TOP] = item.
Step 5: End PUSH operation.
  POP Operation:
Step 1: Check if TOP == -1.
Step 2: If true, display "Stack Underflow".
Step 3: Else set item = stack[TOP].
Step 4: Decrement TOP by 1.
Step 5: Return deleted item.
  PEEK Operation:
Step 1: Check if TOP == -1.
Step 2: If true, display "Stack is Empty".
Step 3: Else set item = stack[TOP].
Step 4: Display item.
Step 5: End PEEK operation.

CODE:
 #include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    // Check for stack overflow before inserting
    if (top >= MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = x; // Insert element into stack
    }
}

int pop()
{
    // Check for stack underflow before deletion
    if (top < 0)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        int value = stack[top];
        top--; // Remove top element
        return value;
    }
}

int peek()
{
    // Return top element without removing it
    if (top < 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int empty()
{
    // Check if the stack is empty
    return top == -1;
}

void display()
{
    // Display all elements in the stack
    if (empty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice, value;
    int n;

    // Get stack size from user
    printf("Enter total size of stack (max %d): ", MAX);
    scanf("%d", &n);

    // Check if size exceeds limit
    if (n > MAX)
    {
        printf("Size exceeds limit\n");
        return 0;
    }

    // Menu-driven stack operations
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Push operation
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                // Pop operation
                value = pop();
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                // Peek operation
                value = peek();
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;

            case 4:
                // Display operation
                display();
                break;

            case 5:
                // Exit the program
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
