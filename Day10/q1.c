/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char arr[100];
    printf("Enter a string to check if it's palindrome or not: ");
    scanf("%s",arr);
    int n=strlen(arr);
    int lo=0;
    int hi=n-1;
    while(lo<=hi)
    {
        if(arr[lo]==arr[hi])
        {
            lo++;
            hi--;
        }
        else{
            printf("NO");
            return -1;
        }
    }
    printf("YES");
    return 0;
}