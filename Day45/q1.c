/*
Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3
*/
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int val;
    struct Node *left,*right;
};

struct Queue 
{
    struct Node **arr;
    int front,rear,size;
};

struct Queue* createQueue(int size) 
{
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->arr=(struct Node**)malloc(size*sizeof(struct Node*));
    q->front=0;
    q->rear=0;
    q->size=size;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) 
{
    q->arr[q->rear++]=node;
}

struct Node* dequeue(struct Queue* q) 
{
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) 
{
    return q->front==q->rear;
}

struct Node* newNode(int val) 
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->val=val;
    node->left=node->right=NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) 
{
    if(n==0 || arr[0]==-1) return NULL;
    struct Node* root=newNode(arr[0]);
    struct Queue* q=createQueue(n);
    enqueue(q,root);
    int i=1;
    while(!isEmpty(q) && i<n) 
    {
        struct Node* curr=dequeue(q);
        if(arr[i]!=-1) 
        {
            curr->left=newNode(arr[i]);
            enqueue(q,curr->left);
        }
        i++;
        if(i<n && arr[i]!=-1) 
        {
            curr->right=newNode(arr[i]);
            enqueue(q,curr->right);
        }
        i++;
    }
    return root;
}

int height(struct Node* root) 
{
    if(root==NULL) return 0;
    int leftH=height(root->left);
    int rightH=height(root->right);
    return 1 + (leftH>rightH ?leftH:rightH);
}
int main() 
{
    int N;
    printf("Enter the size of tree: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter the level-order traversal (-1 represents NULL):\n");
    for(int i=0;i<N;i++) 
    {
        scanf("%d",&arr[i]);
    }
    struct Node* root=buildTree(arr,N);
    printf("Height of the tree wiil be: ");
    printf("%d\n",height(root));
    return 0;
}