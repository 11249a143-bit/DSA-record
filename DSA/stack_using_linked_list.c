                                                                           //STACK USING LINKED LIST//

//Aim: To perform stack operations using a linked list//

🧭 Algorithm:

PUSH Operation (Insert at Top)

Step 1: Create a new node.
Step 2: If memory not available, display "Stack Overflow".
Step 3: Set new node → data = item.
Step 4: Set new node → next = top.
Step 5: Set top = new node.
Step 6: End PUSH operation.

POP Operation (Delete from Top)

Step 1: Check if top == NULL.
Step 2: If true, display "Stack Underflow".
Step 3: Else set temp = top.
Step 4: Set item = top → data.
Step 5: Move top = top → next.
Step 6: Free temp node.
Step 7: Return deleted item.
Step 8: End POP operation.

PEEK Operation

Step 1: Check if top == NULL.
Step 2: If true, display "Stack is Empty".
Step 3: Else display top → data.
Step 4: End PEEK operation.

DISPLAY Operation

Step 1: Check if top == NULL.
Step 2: If true, display "Stack is Empty".
Step 3: Else, traverse from top to NULL.
Step 4: Print each node’s data.
Step 5: End DISPLAY operation.
  
🧭 Code:

  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// PUSH operation
void push(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// POP operation
int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node *temp = top;
    int value = temp->data;

    top = top->next;
    free(temp);

    return value;
}

// PEEK operation
int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// DISPLAY operation
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    struct Node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                value = peek();
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
