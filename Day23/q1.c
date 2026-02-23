/*
Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node* next;
};
struct node* createNode(int data) 
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->info=data;
    new->next = NULL;
    return new;
}

struct node* insertEnd(struct node* head, int data) 
{
    struct node* new=createNode(data);
    if(head==NULL) 
    {
        return new;
    }
    struct node* temp=head;
    while(temp->next!=NULL) 
    {
        temp=temp->next;
    }
    temp->next=new;
    return head;
}

struct node* mergeList(struct node* l1,struct node* l2) 
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    struct node* result=NULL;
    if(l1->info <= l2->info) 
    {
        result=l1;
        result->next=mergeList(l1->next,l2);
    } 
    else 
    {
        result=l2;
        result->next=mergeList(l1,l2->next);
    }
    return result;
}

void printList(struct node* head) 
{
    struct node* temp=head;
    while(temp!=NULL) 
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
}

int main() 
{
    int n,m,i,val;
    struct node* list1=NULL;
    struct node* list2=NULL;
    printf("Enter the size of Linked List-1: ");
    scanf("%d",&n);
    printf("Enter the elements of Linked List-1:\n");
    for(i=0;i<n;i++) 
    {
        scanf("%d",&val);
        list1=insertEnd(list1,val);
    }
    printf("Enter the size of Linked List-2: ");
    scanf("%d",&m);
    printf("Enter the elements of Linked List-2:\n");
    for(i=0;i<m;i++) 
    {
        scanf("%d",&val);
        list2=insertEnd(list2,val);
    }
    struct node* merged=mergeList(list1,list2);
    printf("\nList after Merging:\n");
    printList(merged);
    return 0;
}