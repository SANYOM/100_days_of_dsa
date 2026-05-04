/*
Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int start,end;
}Interval;

int cmp(const void* a,const void* b){
    return ((Interval*)a)->start-((Interval*)b)->start;
}

void swap(int* a,int* b){int t=*a;*a=*b;*b=t;}

void heapify(int heap[],int n,int i){
    int smallest=i,l=2*i+1,r=2*i+2;
    if(l<n&&heap[l]<heap[smallest])smallest=l;
    if(r<n&&heap[r]<heap[smallest])smallest=r;
    if(smallest!=i){swap(&heap[i],&heap[smallest]);heapify(heap,n,smallest);}
}

int minRooms(Interval arr[],int n){
    qsort(arr,n,sizeof(Interval),cmp);
    int heap[n],size=0,maxRooms=0;
    for(int i=0;i<n;i++){
        if(size>0&&heap[0]<=arr[i].start){
            heap[0]=arr[i].end;
            heapify(heap,size,0);
        }else{
            heap[size++]=arr[i].end;
            for(int j=size/2-1;j>=0;j--)heapify(heap,size,j);
        }
        if(size>maxRooms)maxRooms=size;
    }
    return maxRooms;
}

int main(){
    int n; scanf("%d",&n);
    Interval arr[n];
    for(int i=0;i<n;i++)scanf("%d%d",&arr[i].start,&arr[i].end);
    printf("%d\n",minRooms(arr,n));
    return 0;
}
