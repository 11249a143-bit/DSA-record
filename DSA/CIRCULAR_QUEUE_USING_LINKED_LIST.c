                                  🔵 //CIRCULAR QUEUE USING LINKED LIST//
🧭 Aim:

To perform circular queue operations (enqueue and dequeue) using linked list.

🧭 Algorithm:

BEGIN

   1.  Create a node structure containing data and next pointer.

   2.  Initialize the queue by setting front = NULL and rear = NULL.

   3.  Repeat the following steps until user enters “no”:
       a. Display menu with options: 1. Enqueue, 2. Dequeue.
       b. If user selects Enqueue:
        i. Create a new node and store the item.
        ii. If queue is empty (front == NULL):
         • Set front = rear = newnode.
         • Make it circular by setting rear->next = front.
        iii. Else:
         • Insert newnode after rear.
         • Update rear = newnode.
         • Maintain circular link (rear->next = front).
       c. If user selects Dequeue:
        i. If queue is empty, print underflow.
        ii. Else if only one node (front == rear):
         • Delete the only node and set both pointers to NULL.
        iii. Else:
         • Store the value of front.
         • Move front = front->next.
         • Update circular link (rear->next = front).
         • Delete old front node.
       d. Ask user if they want to continue.

  4.   End the process when user enters “no”.
       END

program:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int item) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;

    if (front == NULL) { 
        // Queue empty
        front = rear = newnode;
        rear->next = front;  // Make circular
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;  // Maintain circular structure
    }

    printf("\nentered item: %d\n", item);
}

void dequeue() {
    if (front == NULL) {
        printf("\nqueue is underflow\n");
        return;
    }

    struct node *temp = front;
    int item;

    if (front == rear) { 
        // Only one node
        item = front->data;
        free(temp);
        front = rear = NULL;
    } else {
        item = front->data;
        front = front->next;
        rear->next = front;  // Maintain circular link
        free(temp);
    }

    printf("\ndeleted item = %d\n", item);
}

int main() {
    int op, item;
    char choice[5];

    do {
        printf("\n enter the operation of queue:\n1.enqueue\n2.dequeue\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("enter the item:\n");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            default:
                printf("invalid operation");
                return 0;
        }

        printf("\n enter your choice to repeat or not yes or no:\n");
        scanf("%s", choice);

    } while (strcmp(choice, "no"));

    return 0;
}
