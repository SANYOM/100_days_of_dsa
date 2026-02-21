/*
Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* next;
};
int main()
{
    int n;
    printf("Enter the size of Linked List: ");
    scanf("%d",&n);
    struct node*ptr=NULL,*head=NULL,*temp=NULL;
    printf("Enter the elements of Linked List:\n");
    for(int i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr->next=temp;
        }
        ptr=temp;
    }
    ptr=head;
    printf("Printing the Linked List: ");
    while(ptr!=NULL)
    {
        if(ptr->next==NULL)
        {
            printf("%d",ptr->info);
            return 0;
        }
        printf("%d->",ptr->info);
        ptr=ptr->next;
    }
    return 0;
}