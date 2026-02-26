/*
Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node*next;
    struct node*prev;
};

struct node* head=NULL;

void insert(int);
void display();

int main()
{
    int n;
    printf("Enter the number of nodes in LL: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int val;
        printf("Enter the value of node %d:",i+1);
        scanf("%d",&val);
        insert(val);
        printf("Your LL will look like:\n");
        display();
    }
    return 0;
}

void insert(int val)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->info=val;
    temp->next=NULL;
    temp->prev=NULL;
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
        temp->prev=ptr;
    }
    return;
}

void display()
{
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->next==NULL)
        {
            printf("%d->NULL",ptr->info);   
            break; 
        }
        printf("%d->",ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}