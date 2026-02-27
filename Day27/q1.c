/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*next;
};

void create(struct node**,int);
void display(struct node*);
int intersection(struct node*,struct node*);

struct node* head1=NULL;
struct node* head2=NULL;

int main()
{
    int n1,n2,val;

    printf("Enter the size of LL-1: ");
    scanf("%d",&n1);
    printf("Enter the elements of LL-1\n");

    for(int i=0;i<n1;i++)
    {
        printf("Enter the value of node %d: ",i+1);
        scanf("%d",&val);
        create(&head1,val);
        display(head1);
    }

    printf("Enter the size of LL-2: ");
    scanf("%d",&n2);    
    printf("Enter the elements of LL-2\n");

    for(int i=0;i<n2;i++)
    {
        printf("Enter the value of node %d: ",i+1);
        scanf("%d",&val);
        create(&head2,val);
        display(head2);
    }

    int ans=intersection(head1,head2);
    printf("The value at intersection node is: %d",ans);

    return 0;
}
void create(struct node** head,int val)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->info=val;
    temp->next=NULL;

    if(*head==NULL)
    {
        *head=temp;
    }
    else
    {
        struct node*ptr=*head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void display(struct node*head)
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }

    struct node*ptr=head;
    printf("Your LL will look like:\n");

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
    printf("\n");
}

int intersection(struct node*head1,struct node*head2)
{
    struct node*ptr1=head1;
    while(ptr1!=NULL)
    {
        struct node*ptr2=head2;
        while(ptr2!=NULL)
        {
            if(ptr1->info==ptr2->info)
            {
                return ptr1->info;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    
    printf("\nNO INTERSECTION\n");
    exit(0);
}