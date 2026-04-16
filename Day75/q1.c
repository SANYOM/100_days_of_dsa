/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int sum,index;
    struct Node*next;
};
struct Node*createNode(int sum,int index){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->sum=sum; newNode->index=index; newNode->next=NULL;
    return newNode;
}
int hash(int sum,int m){ return (sum%m+m)%m; }

int longestZeroSum(int arr[],int n){
    int maxLen=0,sum=0,m=10007;
    struct Node*table[m];
    for(int i=0;i<m;i++) table[i]=NULL;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0) maxLen=i+1;
        int h=hash(sum,m);
        struct Node*temp=table[h];
        int found=0;
        while(temp){
            if(temp->sum==sum){
                int len=i-temp->index;
                if(len>maxLen) maxLen=len;
                found=1; break;
            }
            temp=temp->next;
        }
        if(!found){
            struct Node*newNode=createNode(sum,i);
            newNode->next=table[h];
            table[h]=newNode;
        }
    }
    return maxLen;
}

int main(){
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("%d\n",longestZeroSum(arr,n));
    return 0;
}
