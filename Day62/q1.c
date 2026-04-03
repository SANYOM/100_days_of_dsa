/*
Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int vertex;
    struct Node*next;
};
struct Node*createNode(int v)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}
void addEdge(struct Node*adj[],int u,int v,int directed)
{
    struct Node*newNode=createNode(v);
    newNode->next=adj[u];
    adj[u]=newNode;
    if(!directed)
    {
        newNode=createNode(u);
        newNode->next=adj[v];
        adj[v]=newNode;
    }
}
void printGraph(struct Node*adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d:",i);
        struct Node*temp=adj[i];
        while(temp)
        {
            printf(" %d",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    struct Node*adj[n];
    for(int i=0;i<n;i++) adj[i]=NULL;
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(adj,u,v,0); // 0 for undirected, change to 1 for directed
    }
    printGraph(adj,n);
    return 0;
}
