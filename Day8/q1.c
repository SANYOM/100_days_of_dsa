/*
Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32
*/
#include<stdio.h>
int power(int a,int b)
{
    if(b==1)
    {
        return a;
    }
    a*=power(a,b-1);
}
int main()
{
    int a,b;
    printf("Enter the element and it's power: ");
    scanf("%d %d",&a,&b);
    int ans=power(a,b);
    printf("The answer is: ");
    printf("%d",ans);
}