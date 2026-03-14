/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/

#include <stdio.h>
#include <stdlib.h>

struct Queue 
{
    int front,rear,size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) 
{
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity=capacity;
    queue->front=0;
    queue->size=0;
    queue->rear=capacity-1;
    queue->array=(int*)malloc(queue->capacity*sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) 
{
    return (queue->size==queue->capacity);
}

int isEmpty(struct Queue* queue) 
{
    return (queue->size==0);
}

void enqueue(struct Queue* queue, int item) 
{
    if (isFull(queue)) return;
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->array[queue->rear]=item;
    queue->size++;
}

int dequeue(struct Queue* queue) 
{
    if (isEmpty(queue)) return -1;
    int item=queue->array[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->size--;
    return item;
}

void reverseQueue(struct Queue* queue) 
{
    int* stack=(int*)malloc(queue->capacity*sizeof(int));
    int top=-1;
    while (!isEmpty(queue)) 
    {
        stack[++top]=dequeue(queue);
    }
    while(top>=0) 
    {
        enqueue(queue,stack[top--]);
    }
    free(stack);
}

int main() 
{
    int N;
    printf("Enter the size of queue: ");
    scanf("%d", &N);
    struct Queue* queue=createQueue(N);
    printf("Enter the elements of queue:\n");
    for (int i=0;i<N;i++) 
    {
        int x;
        scanf("%d",&x);
        enqueue(queue,x);
    }
    reverseQueue(queue);
    while(!isEmpty(queue)) 
    {
        printf("%d ",dequeue(queue));
    }
    return 0;
}