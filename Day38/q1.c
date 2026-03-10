/*
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100  

typedef struct 
{
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *dq) 
{
    dq->front=-1;
    dq->rear=-1;
    dq->size=0;
}

bool empty(Deque *dq) 
{
    return dq->size==0;
}

int size(Deque *dq) 
{
    return dq->size;
}

void push_front(Deque *dq,int value) 
{
    if(dq->size==MAX) 
    {
        printf("Deque overflow!\n");
        return;
    }
    if(dq->front==-1) 
    { 
        dq->front=dq->rear=0;
    } 
    else 
    {
        dq->front=(dq->front-1+MAX)%MAX;
    }
    dq->arr[dq->front]=value;
    dq->size++;
}

void push_back(Deque *dq,int value)
{
    if(dq->size==MAX) 
    {
        printf("Deque overflow!\n");
        return;
    }
    if(dq->rear==-1) 
    {
        dq->front=dq->rear=0;
    } 
    else 
    {
        dq->rear=(dq->rear+1)%MAX;
    }
    dq->arr[dq->rear]=value;
    dq->size++;
}

void pop_front(Deque *dq) 
{
    if(empty(dq)) 
    {
        printf("Deque underflow!\n");
        return;
    }
    dq->front=(dq->front+1)%MAX;
    dq->size--;
    if(dq->size==0) dq->front=dq->rear=-1;
}

void pop_back(Deque *dq) 
{
    if(empty(dq)) 
    {
        printf("Deque underflow!\n");
        return;
    }
    dq->rear=(dq->rear-1+MAX)%MAX;
    dq->size--;
    if(dq->size==0) dq->front=dq->rear=-1;
}

int front(Deque *dq)
{
    if(empty(dq)) 
    {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->front];
}

int back(Deque *dq) 
{
    if(empty(dq)) 
    {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

void clear(Deque *dq) 
{
    dq->front=dq->rear=-1;
    dq->size=0;
}

void printDeque(Deque *dq) 
{
    if(empty(dq)) 
    {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque: ");
    int i=dq->front;
    for(int count=0;count<dq->size;count++) 
    {
        printf("%d ",dq->arr[i]);
        i=(i+1)%MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);
    int n;
    printf("Enter the number of operations: ");
    scanf("%d",&n); 
    for(int i=0;i<n;i++) 
    {
        printf("Enter the operation %d:\n",i+1);
        char op[20];
        scanf("%s",op);

        if(strcmp(op,"push_back")==0) 
        {
            int val;
            printf("Enter the value to push back: ");
            scanf("%d",&val);
            push_back(&dq,val);
        } 
        else if(strcmp(op,"push_front")==0) 
        {
            int val;
            printf("Enter the value to push front: ");
            scanf("%d",&val);
            push_front(&dq,val);
        } 
        else if(strcmp(op,"pop_back")==0) 
        {
            pop_back(&dq);
        } 
        else if(strcmp(op,"pop_front")==0) 
        {
            pop_front(&dq);
        } 
        else if (strcmp(op,"front")==0)
        {
            printf("Front: %d\n",front(&dq));
        } 
        else if(strcmp(op,"back")==0) 
        {
            printf("Back: %d\n",back(&dq));
        } 
        else if(strcmp(op,"size")==0) 
        {
            printf("Size: %d\n",size(&dq));
        } 
        else if(strcmp(op, "empty")==0) 
        {
            printf("Empty: %s\n",empty(&dq) ? "true" : "false");
        } 
        else if(strcmp(op, "clear")== 0) 
        {
            clear(&dq);
        } 
        else if(strcmp(op,"print")==0) 
        {
            printDeque(&dq);
        }
        else
        {
            printf("Operation is unavailable or invalid.");
            exit(0);
        }
    }
    return 0;
}