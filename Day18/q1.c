/*
Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/
#include<stdio.h>
void reverse(int* arr,int lo,int hi)
{
    while(lo<=hi)
    {
        int temp=arr[lo];
        arr[lo]=arr[hi];
        arr[hi]=temp;
        lo++;
        hi--;
    }
}
int main()
{
    int n,k;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the position k: ");
    scanf("%d",&k);
    k=k%n;
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    printf("Elements of array after rotation:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

    