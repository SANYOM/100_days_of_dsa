/*
Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

int height(struct Node* root) 
{
    if(root==NULL)
        return 0;
    else 
    {
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        return (leftHeight>rightHeight ? leftHeight : rightHeight)+1;
    }
}

int main() 
{
    struct Node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->right=createNode(6);
    printf("Height of the binary tree: %d\n", height(root));
    return 0;
}