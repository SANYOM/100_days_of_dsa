/*
Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
*/
#include<stdio.h>
int main()
{
    int n,elem,cnt=0,idx,cmp=0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the elements to be searched in the array: ");
    scanf("%d",&elem);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==elem)
        {
            idx=i;
            cmp++;
            break;
        }
        cmp++;
    }
    printf("Found at index = %d",idx);
    printf("\nComparisons = %d",cmp);
    
}