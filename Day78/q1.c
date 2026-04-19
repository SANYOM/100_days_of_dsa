/*
Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node {
    int vertex, weight;
    struct Node* next;
};
struct Node* createNode(int v,int w){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v; newNode->weight=w; newNode->next=NULL;
    return newNode;
}
void addEdge(struct Node* adj[],int u,int v,int w){
    struct Node* newNode=createNode(v,w);
    newNode->next=adj[u]; adj[u]=newNode;
    newNode=createNode(u,w);
    newNode->next=adj[v]; adj[v]=newNode;
}
int minKey(int key[],int mstSet[],int n){
    int min=INT_MAX,minIndex=-1;
    for(int v=1;v<=n;v++){
        if(!mstSet[v] && key[v]<min){
            min=key[v]; minIndex=v;
        }
    }
    return minIndex;
}
int primMST(struct Node* adj[],int n){
    int key[n+1],mstSet[n+1];
    for(int i=1;i<=n;i++){key[i]=INT_MAX; mstSet[i]=0;}
    key[1]=0; // start from vertex 1
    int total=0;
    for(int count=1;count<=n;count++){
        int u=minKey(key,mstSet,n);
        mstSet[u]=1;
        total+=key[u];
        struct Node* temp=adj[u];
        while(temp){
            int v=temp->vertex,w=temp->weight;
            if(!mstSet[v] && w<key[v]) key[v]=w;
            temp=temp->next;
        }
    }
    return total;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    struct Node* adj[n+1];
    for(int i=1;i<=n;i++) adj[i]=NULL;
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEdge(adj,u,v,w);
    }
    printf("%d\n",primMST(adj,n));
    return 0;
}
