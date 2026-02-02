/*
Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left
*/

#include<stdio.h>
void delete(int*,int,int);
int main()
{
    int n;int pos;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the position at which element is to be deleted from the array: ");
    scanf("%d",&pos);
    delete(arr,n,pos-1);
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",arr[i]);
    }
}
void delete(int* arr,int size,int pos)
{
    for(int i=pos;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[size-1]=-1;
}