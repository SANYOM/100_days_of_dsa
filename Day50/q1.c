/*
Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
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
struct Node*insert(struct Node*root,int value)
{
    if(root==NULL)
    {
        return createNode(value);
    }
    if(value<root->data)
    {
        root->left=insert(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=insert(root->right,value);
    }
    return root;
}
struct Node*search(struct Node*root,int key)
{
    if(root==NULL||root->data==key)
    {
        return root;
    }
    if(key<root->data)
    {
        return search(root->left,key);
    }
    return search(root->right,key);
}
int main()
{
    struct Node*root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,80);
    int key=40;
    struct Node*result=search(root,key);
    if(result!=NULL)
    {
        printf("Key %d found in BST\n",key);
    }
    else
    {
        printf("Key %d not found in BST\n",key);
    }
    return 0;
}
