/*
Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6
*/
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) 
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

struct Queue 
{
    int front,rear,size;
    unsigned capacity;
    struct Node** array;
};

struct Queue* createQueue(unsigned capacity) 
{
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity=capacity;
    queue->front=0;
    queue->size=0;
    queue->rear=capacity-1;
    queue->array=(struct Node**)malloc(queue->capacity*sizeof(struct Node*));
    return queue;
}

int isEmpty(struct Queue* queue) 
{
    return (queue->size==0);
}

void enqueue(struct Queue* queue,struct Node* item) 
{
    if(queue->size==queue->capacity) return;
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->array[queue->rear]=item;
    queue->size++;
}

struct Node* dequeue(struct Queue* queue) 
{
    if(isEmpty(queue)) return NULL;
    struct Node* item=queue->array[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->size--;
    return item;
}

struct Node* buildTree(int arr[],int n) 
{
    if(n==0 || arr[0]==-1) return NULL;

    struct Node* root=newNode(arr[0]);
    struct Queue* queue=createQueue(n);
    enqueue(queue,root);

    int i=1;
    while(i<n) 
    {
        struct Node* current=dequeue(queue);
        if(arr[i]!=-1) 
        {
            current->left=newNode(arr[i]);
            enqueue(queue,current->left);
        }
        i++;
        if(i<n && arr[i]!=-1) 
        {
            current->right=newNode(arr[i]);
            enqueue(queue,current->right);
        }
        i++;
    }
    return root;
}

void inorder(struct Node* root) 
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main() 
{
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    int arr[N];
    printf("Enter the elements of tree(-1 represents NULL):\n");
    for(int i=0;i<N;i++) 
    {
        scanf("%d",&arr[i]);
    }
    struct Node* root=buildTree(arr,N);
    inorder(root);
    return 0;
}