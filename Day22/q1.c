/*
Problem: Count Nodes in Linked List

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
    int cnt=0;
    printf("\nOutput:-\n");
    while(ptr!=NULL)
    {
        printf("%d ",*ptr);
        ptr=ptr->next;
        cnt++;
    }
    printf("\n");
    printf("The total number of nodes in the above Linked List is:%d",cnt);
    return 0;
}