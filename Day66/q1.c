/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
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
void addEdge(struct Node*adj[],int u,int v)
{
    struct Node*newNode=createNode(v);
    newNode->next=adj[u];
    adj[u]=newNode;
}
int DFS(struct Node*adj[],int visited[],int recStack[],int v)
{
    visited[v]=1;
    recStack[v]=1;
    struct Node*temp=adj[v];
    while(temp)
    {
        if(!visited[temp->vertex] && DFS(adj,visited,recStack,temp->vertex)) return 1;
        else if(recStack[temp->vertex]) return 1;
        temp=temp->next;
    }
    recStack[v]=0;
    return 0;
}
int hasCycle(struct Node*adj[],int n)
{
    int visited[n],recStack[n];
    for(int i=0;i<n;i++){visited[i]=0;recStack[i]=0;}
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(DFS(adj,visited,recStack,i)) return 1;
        }
    }
    return 0;
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
        addEdge(adj,u,v); // directed edge
    }
    if(hasCycle(adj,n)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
