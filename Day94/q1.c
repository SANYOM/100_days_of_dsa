/*
Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.
*/
#include<stdio.h>

void countingsort(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++)if(a[i]>max)max=a[i];
    int count[max+1];
    for(int i=0;i<=max;i++)count[i]=0;
    for(int i=0;i<n;i++)count[a[i]]++;
    for(int i=1;i<=max;i++)count[i]+=count[i-1];
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }
    for(int i=0;i<n;i++)a[i]=output[i];
}

int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    countingsort(a,n);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    return 0;
}
