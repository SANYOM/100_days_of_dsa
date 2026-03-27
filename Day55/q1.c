/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.
*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};
struct Node*createNode(int value)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node*buildTree(int arr[],int n)
{
    if(n==0||arr[0]==-1) return NULL;
    struct Node**nodes=(struct Node**)malloc(n*sizeof(struct Node*));
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1) nodes[i]=NULL;
        else nodes[i]=createNode(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(nodes[i]!=NULL)
        {
            int leftIndex=2*i+1;
            int rightIndex=2*i+2;
            if(leftIndex<n) nodes[i]->left=nodes[leftIndex];
            if(rightIndex<n) nodes[i]->right=nodes[rightIndex];
        }
    }
    struct Node*root=nodes[0];
    free(nodes);
    return root;
}
void rightView(struct Node*root)
{
    if(root==NULL) return;
    struct Node*queue[1000];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        int size=rear-front;
        for(int i=0;i<size;i++)
        {
            struct Node*curr=queue[front++];
            if(curr->left!=NULL) queue[rear++]=curr->left;
            if(curr->right!=NULL) queue[rear++]=curr->right;
            if(i==size-1) printf("%d ",curr->data);
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct Node*root=buildTree(arr,N);
    rightView(root);
    return 0;
}
