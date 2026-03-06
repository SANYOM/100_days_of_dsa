/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

Node* push(Node *top, int val) 
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = top;
    return newNode;
}

Node* pop(Node *top, int *val) 
{
    if (!top) return NULL;
    *val = top->data;
    Node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

int main() 
{
    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    Node *stack = NULL;
    char *token = strtok(expr, " ");
    while (token) {
        if (isdigit(token[0])) {
            stack = push(stack, atoi(token));
        } else {
            int b, a;
            stack = pop(stack, &b);
            stack = pop(stack, &a);
            switch (token[0]) {
                case '+': stack = push(stack, a + b); break;
                case '-': stack = push(stack, a - b); break;
                case '*': stack = push(stack, a * b); break;
                case '/': stack = push(stack, a / b); break;
            }
        }
        token = strtok(NULL, " ");
    }

    int result;
    stack = pop(stack, &result);
    printf("%d\n", result);
    return 0;
}