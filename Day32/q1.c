/*
Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10
*/
#include<stdio.h>
#define max 100

int stck[max];
int top=-1;

void push(int,int);
void pop(int);
void display();

int main()
{
    int n,op;
    printf("Enter the size of stack: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int val;
        printf("Enter the value of element %d: ",i+1);
        scanf("%d",&val);
        push(val,n);
    }
    printf("Enter the number of times you want to apply pop operation: ");
    scanf("%d",&op);
    pop(op);
    printf("Your Stack after applying pop operation %d times:\n",op);
    display();
}

void push(int val,int size)
{
    if(top!=size-1)
    {
        stck[++top]=val;
    }
    else
    {
        printf("Overflow");
    }
    return;
}

void pop(int op)
{
    while(op)
    {
        if(top!=-1)
        {
            top--;
            op--;
        }
        else
        {
            printf("Underflow");
        }
    }
    return;
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d ",stck[i]);
        }
        printf("\n");
    }
    return;
}