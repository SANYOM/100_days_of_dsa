/*
Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*next;
};
struct node*head=NULL;
void create(int val);
void display();
struct node* reverse(int,int);
int main()
{
    int n,k;
    printf("Enter the size of LL: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int val;
        printf("Enter the value of node %d:",i+1);
        scanf("%d",&val);
        create(val);
        printf("Your LL will look like:\n");
        display();
    }
    printf("Enter the value of k: ");
    scanf("%d",&k);
    head=reverse(n,k);
    printf("\nLL after rotating it right by k places will look like:\n");
    display();
}
void create(int val)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->info=val;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node*ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return;
}
void display()
{
    struct node*ptr=head;
    while(ptr->next!=NULL)
    {
        printf("%d->",ptr->info);
        ptr=ptr->next;
    }
    printf("%d->NULL",ptr->info);
    printf("\n");
    return;
}
struct node* reverse(int n,int k)
{
    k=k%n;
    struct node*ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=head;
    int steps=n-k;
    struct node*newTail=head;
    for(int i=1;i<steps;i++)
    {
        newTail=newTail->next;
    }
    struct node*newHead=newTail->next;
    newTail->next=NULL;
    return newHead;
}