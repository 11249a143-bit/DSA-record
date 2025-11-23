                                                       //Queue Operations//

//Aim: To perform queue operations using array//

🧭 Algorithm:

ENQUEUE Operation:

Step 1: Check if REAR == MAX - 1.
Step 2: If true, display "Queue Overflow".
Step 3: Else, if FRONT == -1, set FRONT = 0.
Step 4: Increment REAR by 1.
Step 5: Set queue[REAR] = item.
Step 6: End ENQUEUE operation.

DEQUEUE Operation:

Step 1: Check if FRONT == -1 OR FRONT > REAR.
Step 2: If true, display "Queue Underflow".
Step 3: Else set item = queue[FRONT].
Step 4: Increment FRONT by 1.
Step 5: Return deleted item.
Step 6: End DEQUEUE operation.

PEEK Operation:

Step 1: Check if FRONT == -1 OR FRONT > REAR.
Step 2: If true, display "Queue is Empty".
Step 3: Else set item = queue[FRONT].
Step 4: Display item.
Step 5: End PEEK operation.
  
  🧭 Code:
  
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int x)
{
    if (rear >= MAX - 1)   // Overflow
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;     // First element insertion

        rear++;
        queue[rear] = x;   // Insert element
    }
}

// Dequeue operation
int dequeue()
{
    if (front == -1 || front > rear)  // Underflow
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        int value = queue[front];
        front++;     // Move front ahead
        return value;
    }
}

// Peek operation
int peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

// Check if queue is empty
int empty()
{
    return (front == -1 || front > rear);
}

// Display operation
void display()
{
    if (empty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice, value;
    int n;

    // Get queue size from user
    printf("Enter total size of queue (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Size exceeds limit\n");
        return 0;
    }

    // Menu-driven queue operations
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued value: %d\n", value);
                break;

            case 3:
                value = peek();
                if (value != -1)
                    printf("Front value: %d\n", value);
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
