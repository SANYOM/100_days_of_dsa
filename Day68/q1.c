/*
Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
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
void addEdge(struct Node*adj[],int u,int v,int indegree[])
{
    struct Node*newNode=createNode(v);
    newNode->next=adj[u];
    adj[u]=newNode;
    indegree[v]++;
}
void topoSort(struct Node*adj[],int n,int indegree[])
{
    int queue[1000],front=0,rear=0;
    for(int i=0;i<n;i++)
        if(indegree[i]==0) queue[rear++]=i;
    int count=0;
    while(front<rear)
    {
        int v=queue[front++];
        printf("%d ",v);
        count++;
        struct Node*temp=adj[v];
        while(temp)
        {
            indegree[temp->vertex]--;
            if(indegree[temp->vertex]==0) queue[rear++]=temp->vertex;
            temp=temp->next;
        }
    }
    if(count!=n) printf("\nGraph has a cycle, topological ordering not possible");
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    struct Node*adj[n];
    int indegree[n];
    for(int i=0;i<n;i++){adj[i]=NULL;indegree[i]=0;}
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(adj,u,v,indegree); // directed edge
    }
    topoSort(adj,n,indegree);
    return 0;
}
