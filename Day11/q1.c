/*
Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

Test Cases:

Test Case 1:
Input:
2 2
1 2
3 4
5 6
7 8
Output:
6 8
10 12

Test Case 2:
Input:
1 3
10 20 30
1 2 3
Output:
11 22 33

Test Case 3:
Input:
3 1
1
2
3
4
5
6
Output:
5
7
9
*/
#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter the number of rows and columns of array for addition: ");
    scanf("%d%d",&r,&c);
    int arr1[r][c];
    int arr2[r][c];
    int ans[r][c];
    printf("Enter the elements of first array:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("Enter the elements of second array:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("Array after addition:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            ans[i][j]=arr1[i][j]+arr2[i][j];
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}