/*
Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*next;
};
struct node*head=NULL;
void create(int);
void display();
void main()
{
    int n;
    printf("Enter the size of LL: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int val;
        printf("Enter the value of node %d:",i+1);
        scanf("%d",&val);
        create(val);
        display();
    }
    return;
}
void create(int val)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->info=val;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        temp->next=head;
    }
    else
    {
        struct node*ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=head;
    }
    return;
}
void display()
{
    struct node*ptr=head;
    printf("Your LL will look like:\n");
    while(ptr->next!=head)
    {
        printf("%d->",ptr->info);
        ptr=ptr->next;
    }
    printf("%d->HEAD",ptr->info);
    printf("\n");
    return;
}