/*
Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int arr[MAX];
int size=0;

void insert(int x) 
{
    if(size<MAX) 
    {
        arr[size++]=x;
    }
}

int delete() 
{
    if(size==0) return -1;

    int minIndex=0;
    for(int i=1;i<size;i++) 
    {
        if(arr[i]<arr[minIndex]) 
        {
            minIndex=i;
        }
    }

    int deleted=arr[minIndex];
    for(int i=minIndex;i<size-1;i++) 
    {
        arr[i]=arr[i + 1];
    }
    size--;
    return deleted;
}

int peek() 
{
    if(size==0) return -1;

    int minIndex=0;
    for(int i=1;i<size;i++) 
    {
        if(arr[i]<arr[minIndex]) 
        {
            minIndex=i;
        }
    }
    return arr[minIndex];
}

int main() 
{
    int N;
    printf("Enter the number of operations: ");
    scanf("%d",&N);
    char op[10];
    int x;
    for(int i=0;i<N;i++) 
    {
        printf("Enter the operation %d:\n",i+1);
        scanf("%s",op);
        if(strcmp(op,"insert")==0) 
        {
            printf("Enter the value to be inserted: ");
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"delete")==0) 
        {
            printf("%d\n",delete());
        } 
        else if(strcmp(op,"peek")==0) 
        {
            printf("%d\n",peek());
        }
    }
    return 0;
}