                                  //BINARY SEARCH TREE TRAVERSALS//


//Aim:To create a Binary Search Tree (BST) using dynamic insertion and perform Preorder, Inorder, and Postorder Traversals.//

🧭 Algorithm:

🔷 1. Creating a Node
Allocate memory for the new node.
Store the input value in data.
Set both left hand right pointers to NULL.
Return the newly created node.
🔷 2. Inserting into BST
If the tree is empty (root == NULL):
→ Create and return a new node.
If value < root->data:
→ Recursively insert into the left subtree.
Else
→ Recursively insert into the right subtree.
Return the updated root.
🔷 3. Preorder Traversal (Root → Left → Right)
If tree is empty, return.
Visit (print) the root node.
Traverse left subtree (preorder).
Traverse right subtree (preorder).
🔷 4. Inorder Traversal
(Left → Root → Right)
If tree is empty, return.
Traverse left subtree (inorder).
Visit (print) the root node.
Traverse right subtree (inorder).
🔷 5. Postorder Traversal (Left → Right → Root)
If tree is empty, return.
Traverse left subtree (postorder).
Traverse right subtree (postorder).
Visit (print) the root node.
🔷 6. Main Program
Read n (number of elements).
Initialize root = NULL.
For every input value:
→ Insert it into BST using insert().
Display Preorder, Inorder, and Postorder traversals.
End

🧭 Code:

#include <stdio.h>
#include <stdlib.h>

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

// Preorder - Root -> Left -> Right
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder - Left -> Root -> Right
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder - Left -> Right -> Root
void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{

    int n, value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert dynamically into BST
    }

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}
