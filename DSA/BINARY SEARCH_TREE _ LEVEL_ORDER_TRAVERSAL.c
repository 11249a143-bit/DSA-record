                                           //BINARY SEARCH TREE & LEVEL ORDER TRAVERSAL//


//Aim:To create a Binary Search Tree (BST) using dynamic insertion and perform Level Order Traversal (BFS) using a queue//

🧭 Algorithm:

1. Creating a Node
Allocate memory for a new node.
Assign the input value to data.
Set left and right child pointers to NULL.
Return the newly created node.
2. Inserting into BST
If the tree is empty (root == NULL):
→ Create a new node and return it.
If value < root->data:
→ Recursively insert in left subtree.
Else
→ Recursively insert in right subtree.
Return the root to maintain tree structure.
3. Queue Operations (for Level Order Traversal)
a. ENQUEUE(node)
If queue is full → return.
If queue is empty (front == -1) → set front = 0.
Increment rear and insert node into queue.
b. DEQUEUE()
If queue empty (front == -1 OR front > rear) → return NULL.
Return queue[front] and increment front.
4. Level Order Traversal (BFS)
If root is NULL → exit.
Enqqeue the root node.
While the queue is not empty:
a. Dequeue a node → call it current.
b. Print current->data.
c. If current has a left child → enqueue it.
d. If current has a right child → enqueue it.
5. Main Program
Read number of elements (MAX).
Allocate memory for queue of size MAX.
Insert each element into BST using insert().
Display tree using levelOrder().
End.

🧭 Code:

#include <stdio.h>
#include <stdlib.h>

struct Node **queue;
int front = -1, rear = -1, MAX;

// Structure for tree node
// Data, Pointer to left child and Pointer to right child
struct Node
{
    int data;
    struct Node *left, *right;
};

// Node creation
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert the new node and returns root node of the updated tree
struct Node *insert(struct Node *root, int value)
{
    // First node will be root node
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Queue implementation for Level Order Traversal / BFS


void enqueue(struct Node *temp)
{
    if (rear == MAX-1)
        return; // Queue full
    if (front == -1)
        front = 0;
    queue[++rear] = temp;
}

struct Node *dequeue()
{
    if (front == -1 || front > rear)
        return NULL; // Empty
    return queue[front++];
}

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear)
    {
        struct Node *current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main()
{
    int value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &MAX);

    queue = (struct Node **)malloc(MAX * sizeof(struct Node *));

    printf("Enter %d values:\n", MAX);

    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert dynamically into BST
    }

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    return 0;
}
