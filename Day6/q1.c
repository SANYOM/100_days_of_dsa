/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int chk=arr[0];
    int idx=0;
    int num[n];
    num[idx] = arr[0];
    idx++;
    for(int i=1;i<n;i++)
    {
        if(i!=n-1)
        {
            if(arr[i]!=chk)
            {
                num[idx]=arr[i];
                idx++;
                chk=arr[i];
            }
        }
        else
        {
            if(arr[i]!=chk)
            {
                num[idx]=arr[i];   
                idx++;
            }
        }
    }
    for(int i=0;i<idx;i++)
    {
        printf("%d ",num[i]);
    }
}