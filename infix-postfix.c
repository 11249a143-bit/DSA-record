//*Aim : To perform infix to postfix conversion using stack*//

🧭 Algorithm:
 BEGIN
 1. INITIALIZE AN EMPTY STACK AND AN EMPTY POSTFIX STRING.
 2. PUSH '(' ONTO THE STACK AND ADD ')' TO THE END OF THE INFIX EXPRESSION
 3. FOR EACH SYMBOL X IN THE INFIX EXPRESSION, DO:
 a. IF X IS AN OPERAND, ADD X TO THE POSTFIX STRING.
 b. IF X IS '(', PUSH IT ONTO THE STACK.
 c. IF X IS AN OPERATOR, THEN:
 WHILE (STACK IS NOT EMPTY) AND (PRECEDENCE OF TOP OF STACK ≥
 PRECEDENCE OF X):
 POP OPERATOR FROM STACK AND ADD IT TO POSTFIX STRING.

 PUSH X ONTO THE STACK.
  d. IF X IS ')', THEN:
 WHILE THE TOP OF THE STACK IS NOT '(':
 POP OPERATOR FROM STACK AND ADD IT TO POSTFIX STRING.
 POP '(' FROM THE STACK AND DISCARD IT.
 4. END FOR
 5. THE RESULTING POSTFIX STRING IS THE FINAL OUTPUT.
END

🧭 Code:
#include <stdio.h>
#include <stdlib.h>

int top = -1, max;
char *stack;

// Push an element into the stack
void push(char item)
{
    if (top == max - 1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

// Pop an element from the stack
char pop()
{
    if (top == -1)
    {
        printf("Stack underflow/empty\n");
        return '\0';
    }
    else
    {
        char item = stack[top];
        top = top - 1;
        return item;
    }
}

// Return the top element without removing it
char peek()
{
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top];
    }
}

// Return precedence value of operators
int get_precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int main()
{
    printf("Enter the size of infix expression: ");
    scanf("%d", &max);

    // Dynamically allocate memory for stack
    stack = (char *)malloc(max * sizeof(char));
    char infix[max];
    char postfix[max];

    // Read infix expression from user
    printf("Please enter the infix string of size %d: ", max);
    scanf("%s", infix);

    int token_precedence, i = 0, j = 0;
    char c;

    // Process each character of infix expression
    while ((c = infix[i]) != '\0')
    {
        token_precedence = get_precedence(c);

        // If operator found, manage precedence
        if (token_precedence > 0)
        {
            while (token_precedence <= get_precedence(peek()))
            {
                postfix[j++] = pop();
            }
            push(c);
        }
        else
        {
            // Handle parentheses and operands
            switch (c)
            {
            case '(':
                push(c);
                break;
            case ')':
                while (peek() != '(')
                {
                    postfix[j++] = pop();
                }
                pop(); // Remove '(' from stack
                break;
            default:
                postfix[j++] = c; // Operand goes directly to postfix
                break;
            }
        }
        i++;
    }

    // Pop all remaining operators from stack
    while (peek() != '\0')
    {
        char c = pop();
        printf("Popped char %c\n", c);
        postfix[j++] = c;
    }

    // End postfix string
    postfix[j] = '\0';

    // Display final postfix expression
    printf("Postfix notation is: %s\n", postfix);
    return 0;
}
