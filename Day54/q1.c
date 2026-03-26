/*
Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.
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
void zigzagTraversal(struct Node*root)
{
    if(root==NULL) return;
    struct Node*queue[1000];
    int front=0,rear=0;
    queue[rear++]=root;
    int leftToRight=1;
    while(front<rear)
    {
        int size=rear-front;
        int level[size];
        for(int i=0;i<size;i++)
        {
            struct Node*curr=queue[front++];
            level[i]=curr->data;
            if(curr->left!=NULL) queue[rear++]=curr->left;
            if(curr->right!=NULL) queue[rear++]=curr->right;
        }
        if(leftToRight)
        {
            for(int i=0;i<size;i++) printf("%d ",level[i]);
        }
        else
        {
            for(int i=size-1;i>=0;i--) printf("%d ",level[i]);
        }
        leftToRight=!leftToRight;
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
    zigzagTraversal(root);
    return 0;
}
