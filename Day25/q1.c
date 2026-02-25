/*
Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.
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
void print();
int count(int);
int main()
{
    int n,val,key;
    printf("Enter the number of nodes in LL: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of node %d: ",i+1);
        scanf("%d",&val);
        create(val);
        printf("Your LL will look like:\n");
        print();
    }
    printf("\nEnter the key element to count in LL: ");
    scanf("%d",&key);
    int cnt=count(key);
    printf("\nThe number of times the key appears in the linked list is: %d\n",cnt);
    return 0;
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
        ptr=head;        
    }
    return;
}
void print()
{
    struct node*ptr=head;
    while(ptr->next!=NULL)
    {
        printf("%d->",ptr->info);
        ptr=ptr->next;
    }
    printf("%d->NULL\n",ptr->info);
    return;
}
int count(int key)
{
    int cnt=0;
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->info==key)
        {
            cnt++;
        }
        ptr=ptr->next;
    }
    return cnt;
}