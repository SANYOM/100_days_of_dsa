/*
Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Queue 
{
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct Queue* q) 
{
    q->front=q->rear=NULL;
}

void enqueue(struct Queue* q,int x) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;

    if(q->rear==NULL) 
    {
        q->front=q->rear=newNode;
        return;
    }
    q->rear->next=newNode;
    q->rear=newNode;
}

void dequeue(struct Queue* q) 
{
    if(q->front==NULL)
    { 
        printf("-1\n");
        return;
    }
    struct Node* temp=q->front;
    printf("%d\n",temp->data);
    q->front=q->front->next;
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    free(temp);
}

int main() 
{
    int N;
    printf("Enter the number of operations: ");
    scanf("%d",&N);
    struct Queue q;
    initQueue(&q);
    for(int i=0;i<N;i++) 
    {
        printf("Enter the operation number %d:\n",i+1);
        char op[10];
        scanf("%s",op);
        if(op[0]=='e') 
        {
            int val;
            printf("Enter the value to be entered: ");
            scanf("%d",&val);
            enqueue(&q,val);
        } 
        else if(op[0]=='d') 
        {
            dequeue(&q);
        }
    }
    return 0;
}