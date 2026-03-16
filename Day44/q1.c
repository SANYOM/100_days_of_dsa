/*
Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1
*/
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) 
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

struct Queue 
{
    int front, rear, size, capacity;
    struct Node** arr;
};

struct Queue* createQueue(int capacity) 
{
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->capacity=capacity;
    q->front=0;
    q->size=0;
    q->rear=capacity-1;
    q->arr=(struct Node**)malloc(capacity*sizeof(struct Node*));
    return q;
}

int isEmpty(struct Queue* q)
{
    return q->size==0;
}

void enqueue(struct Queue* q, struct Node* node) 
{
    if(q->size==q->capacity) return;
    q->rear=(q->rear+1)%q->capacity;
    q->arr[q->rear]=node;
    q->size++;
}

struct Node* dequeue(struct Queue* q) 
{
    if (isEmpty(q)) return NULL;
    struct Node* node=q->arr[q->front];
    q->front=(q->front+1)%q->capacity;
    q->size--;
    return node;
}

struct Node* buildTree(int arr[], int n) 
{
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);
    int i=1;
    while(i<n) 
    {
        struct Node* current = dequeue(q);
        if(arr[i]!=-1) 
        {
            current->left=newNode(arr[i]);
            enqueue(q,current->left);
        }
        i++;
        if (i<n && arr[i]!=-1) 
        {
            current->right = newNode(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }
    return root;
}

void inorder(struct Node* root) 
{
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) 
{
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) 
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() 
{
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    int arr[N];
    printf("Enter the elements:\n");
    for (int i=0;i<N;i++) scanf("%d", &arr[i]);
    struct Node* root=buildTree(arr,N);
    printf("Outputs:\n");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}