/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
struct Pair
{
    struct Node*node;
    int hd;
};
void verticalOrder(struct Node*root)
{
    if(root==NULL) return;
    struct Pair queue[1000];
    int front=0,rear=0;
    queue[rear].node=root;
    queue[rear].hd=0;
    rear++;
    int minHD=INT_MAX,maxHD=INT_MIN;
    int map[2000][100];
    int count[2000]={0};
    while(front<rear)
    {
        struct Pair p=queue[front++];
        struct Node*curr=p.node;
        int hd=p.hd;
        if(curr!=NULL)
        {
            if(hd<minHD) minHD=hd;
            if(hd>maxHD) maxHD=hd;
            int index=hd+1000;
            map[index][count[index]++]=curr->data;
            if(curr->left!=NULL)
            {
                queue[rear].node=curr->left;
                queue[rear].hd=hd-1;
                rear++;
            }
            if(curr->right!=NULL)
            {
                queue[rear].node=curr->right;
                queue[rear].hd=hd+1;
                rear++;
            }
        }
    }
    for(int hd=minHD;hd<=maxHD;hd++)
    {
        int index=hd+1000;
        for(int i=0;i<count[index];i++)
        {
            printf("%d ",map[index][i]);
        }
        printf("\n");
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
    verticalOrder(root);
    return 0;
}
