/*
Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* next;
};
void remove_key(int);
void print();
void create();
struct node*head=NULL;
void remove_key(int key)
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    if(head->info==key)
    {
        struct node*temp=head;
        head=head->next;
        free(temp);
        return;
    }
    struct node*prev=head,*ptr=head;
    while(ptr!=NULL && ptr->info!=key)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        prev->next=ptr->next;
        free(ptr);
        return;
    }
    else
    {
        printf("Key is not present in the LL\n");
        exit(0);
    }
    return;
}
void print()
{
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->next!=NULL)
        {
            printf("%d->",ptr->info);
        }
        else
        {
            printf("%d->NULL",ptr->info);
        }
        ptr=ptr->next;
    }
}
void create(int elem)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->info=elem;
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
}
int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int elem;
        printf("Enter the value of node %d:",i+1);
        scanf("%d",&elem);
        create(elem);
        printf("Your LL will look like:\n");
        print();
        printf("\n");
    }
    int key;
    printf("\nEnter the integer key you want to delete: ");
    scanf("%d",&key);
    remove_key(key);
    printf("LL after the removal of key:\n");
    print();
    return 0;
}