/*
Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node*next;
};

struct Queue 
{
    struct Node*front;
    struct Node*rear;
};

void initQueue(struct Queue*q) 
{
    q->front=q->rear=NULL;
}

void enqueue(struct Queue*q,int value) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(q->rear==NULL) 
    {
        q->front=q->rear=newNode;
        return;
    }
    q->rear->next=newNode;
    q->rear=newNode;
}

int dequeue(struct Queue*q) 
{
    if(q->front==NULL) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp=q->front;
    int value=temp->data;
    q->front=q->front->next;
    if(q->front==NULL)
        q->rear=NULL;
    free(temp);
    return value;
}

void display(struct Queue*q) 
{
    struct Node* temp=q->front;
    while(temp!=NULL) 
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() 
{
    int n,i,x;
    struct Queue q;
    initQueue(&q);
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements of the queue:\n");
    for(i=0;i<n;i++) 
    {
        scanf("%d",&x);
        enqueue(&q,x);
    }
    printf("Queue elements from front to rear:\n");
    display(&q);
    return 0;
}