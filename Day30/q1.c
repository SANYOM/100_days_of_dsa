/*
Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.
*/
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int coeff;
    int exp;
    struct node* next;
};
struct node* createNode(int coeff,int exp) 
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->coeff=coeff;
    newNode->exp=exp;
    newNode->next=NULL;
    return newNode;
}
void insertNode(struct node** head,int coeff,int exp) 
{
    struct node* newNode=createNode(coeff,exp);
    if(*head==NULL) 
    {
        *head=newNode;
    } 
    else 
    {
        struct node* temp=*head;
        while(temp->next!=NULL) 
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void printPolynomial(struct node* head) 
{
    struct node* temp=head;
    while(temp!=NULL) 
    {
        printf("%d",temp->coeff);
        if(temp->exp!=0) 
        {
            printf("x^%d",temp->exp);
        }
        if(temp->next!=NULL) 
        {
            printf(" + ");
        }
        temp=temp->next;
    }
    printf("\n");
}
int main() 
{
    int n,coeff,exp;
    struct node* poly=NULL;
    printf("Enter the size of LL: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        printf("Enter the coefficient and exponent of node %d:",i+1);
        scanf("%d %d",&coeff,&exp);
        insertNode(&poly,coeff,exp);
    }
    printPolynomial(poly);
    return 0;
}