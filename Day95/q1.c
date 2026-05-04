/*
Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.
*/
#include<stdio.h>
#include<stdlib.h>

void insertionsort(float a[],int n){
    for(int i=1;i<n;i++){
        float key=a[i]; int j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j]; j--;
        }
        a[j+1]=key;
    }
}

void bucketsort(float a[],int n){
    int bcount=n;
    float buckets[bcount][n];
    int size[bcount];
    for(int i=0;i<bcount;i++)size[i]=0;
    for(int i=0;i<n;i++){
        int bi=(int)(a[i]*bcount);
        buckets[bi][size[bi]++]=a[i];
    }
    int idx=0;
    for(int i=0;i<bcount;i++){
        if(size[i]>0){
            insertionsort(buckets[i],size[i]);
            for(int j=0;j<size[i];j++)a[idx++]=buckets[i][j];
        }
    }
}

int main(){
    int n; scanf("%d",&n);
    float a[n];
    for(int i=0;i<n;i++)scanf("%f",&a[i]);
    bucketsort(a,n);
    for(int i=0;i<n;i++)printf("%f ",a[i]);
    return 0;
}
