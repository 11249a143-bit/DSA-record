                                                  //STRING REVERSAL//

//*Aim : To perform string reverse using stack operation*//

🧭 Algorithm:
Step 1: Start the program.
Step 2: Initialize TOP = -1 and get the size of the string.
Step 3: Input the string from the user.
Step 4: For each character in the string, perform PUSH to insert it into the stack.
Step 5: Once all characters are pushed, start POP operations to remove and print each character.
Step 6: Continue popping until the stack is empty.
Step 7: Display the reversed string.
Step 8: Stop the program.        


🧭Code:
#include<stdio.h>

int top = -1;
int size;
char stack[50];

// Push a character into the stack
void push(char item)
{
    if(top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow\n");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

// Pop a character from the stack
char pop()
{
    char temp = stack[top];
    top = top - 1;
    return temp;
}

int main()
{
    // Read the size of the string
    printf("Enter the size of string to reverse: ");
    scanf("%d", &size);

    char input[size];

    // Read the string from the user
    printf("Enter the string of size %d to reverse: ", size);
    scanf("%s", input);

    // Push all characters of the string onto the stack
    for (int i = 0; i <= size - 1; i++)
    {
        push(input[i]);
    }

    // Pop all elements to print the reversed string
    printf("Reversed string is:\n");
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%c", pop());
    }
}
