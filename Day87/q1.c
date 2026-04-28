/*
Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64
*/
#include<stdio.h>

void bubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]){
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
}

int binarySearch(int a[],int n,int x){
    int l=0,r=n-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(a[m]==x) return m;
        else if(a[m]<x) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    bubbleSort(a,n);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    int x; scanf("%d",&x);
    int idx=binarySearch(a,n,x);
    if(idx!=-1) printf("%d found at index %d\n",x,idx);
    else printf("%d not found\n",x);
    return 0;
}
