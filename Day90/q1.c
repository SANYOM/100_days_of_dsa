/*
Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.
*/
#include<stdio.h>

int isPossible(int boards[],int n,int k,int limit){
    int painters=1,sum=0;
    for(int i=0;i<n;i++){
        if(boards[i]>limit) return 0;
        if(sum+boards[i]>limit){
            painters++; sum=boards[i];
            if(painters>k) return 0;
        }else sum+=boards[i];
    }
    return 1;
}

int main(){
    int n,k; scanf("%d%d",&n,&k);
    int boards[n];
    for(int i=0;i<n;i++) scanf("%d",&boards[i]);
    int l=0,r=0,ans=0;
    for(int i=0;i<n;i++){ if(boards[i]>l) l=boards[i]; r+=boards[i]; }
    while(l<=r){
        int mid=l+(r-l)/2;
        if(isPossible(boards,n,k,mid)){ ans=mid; r=mid-1; }
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
