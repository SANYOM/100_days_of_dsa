/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node {
    int vertex, weight;
    struct Node* next;
};
struct Node* createNode(int v,int w) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v; newNode->weight=w; newNode->next=NULL;
    return newNode;
}
void addEdge(struct Node* adj[],int u,int v,int w) {
    struct Node* newNode=createNode(v,w);
    newNode->next=adj[u];
    adj[u]=newNode;
}

struct HeapNode {
    int v, dist;
};
struct MinHeap {
    int size, capacity;
    int *pos;
    struct HeapNode **array;
};
struct HeapNode* newHeapNode(int v,int dist) {
    struct HeapNode* node=(struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->v=v; node->dist=dist; return node;
}
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos=(int*)malloc(capacity*sizeof(int));
    heap->size=0; heap->capacity=capacity;
    heap->array=(struct HeapNode**)malloc(capacity*sizeof(struct HeapNode*));
    return heap;
}
void swapHeapNode(struct HeapNode** a,struct HeapNode** b) {
    struct HeapNode* t=*a; *a=*b; *b=t;
}
void minHeapify(struct MinHeap* heap,int idx) {
    int smallest=idx; int left=2*idx+1; int right=2*idx+2;
    if(left<heap->size && heap->array[left]->dist<heap->array[smallest]->dist) smallest=left;
    if(right<heap->size && heap->array[right]->dist<heap->array[smallest]->dist) smallest=right;
    if(smallest!=idx) {
        struct HeapNode* smallestNode=heap->array[smallest];
        struct HeapNode* idxNode=heap->array[idx];
        heap->pos[smallestNode->v]=idx;
        heap->pos[idxNode->v]=smallest;
        swapHeapNode(&heap->array[smallest],&heap->array[idx]);
        minHeapify(heap,smallest);
    }
}
int isEmpty(struct MinHeap* heap) { return heap->size==0; }
struct HeapNode* extractMin(struct MinHeap* heap) {
    if(isEmpty(heap)) return NULL;
    struct HeapNode* root=heap->array[0];
    struct HeapNode* lastNode=heap->array[heap->size-1];
    heap->array[0]=lastNode;
    heap->pos[root->v]=heap->size-1;
    heap->pos[lastNode->v]=0;
    heap->size--; minHeapify(heap,0);
    return root;
}
void decreaseKey(struct MinHeap* heap,int v,int dist) {
    int i=heap->pos[v];
    heap->array[i]->dist=dist;
    while(i && heap->array[i]->dist<heap->array[(i-1)/2]->dist) {
        heap->pos[heap->array[i]->v]=(i-1)/2;
        heap->pos[heap->array[(i-1)/2]->v]=i;
        swapHeapNode(&heap->array[i],&heap->array[(i-1)/2]);
        i=(i-1)/2;
    }
}
int isInMinHeap(struct MinHeap* heap,int v) { return heap->pos[v]<heap->size; }

void dijkstra(struct Node* adj[],int n,int src) {
    int dist[n];
    for(int v=0;v<n;v++) dist[v]=INT_MAX;
    struct MinHeap* heap=createMinHeap(n);
    for(int v=0;v<n;v++) {
        heap->array[v]=newHeapNode(v,dist[v]);
        heap->pos[v]=v;
    }
    heap->array[src]=newHeapNode(src,0);
    heap->pos[src]=src;
    dist[src]=0; heap->size=n;
    decreaseKey(heap,src,dist[src]);
    while(!isEmpty(heap)) {
        struct HeapNode* minNode=extractMin(heap);
        int u=minNode->v;
        struct Node* temp=adj[u];
        while(temp) {
            int v=temp->vertex;
            if(isInMinHeap(heap,v) && dist[u]!=INT_MAX && temp->weight+dist[u]<dist[v]) {
                dist[v]=dist[u]+temp->weight;
                decreaseKey(heap,v,dist[v]);
            }
            temp=temp->next;
        }
    }
    for(int i=0;i<n;i++) printf("Vertex %d Distance %d\n",i,dist[i]);
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    struct Node* adj[n];
    for(int i=0;i<n;i++) adj[i]=NULL;
    for(int i=0;i<m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEdge(adj,u,v,w); // directed weighted edge
    }
    int src; scanf("%d",&src);
    dijkstra(adj,n,src);
    return 0;
}
