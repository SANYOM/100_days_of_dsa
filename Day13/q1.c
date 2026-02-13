/*
Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9
*/
#include <stdio.h>
void spiral(int m,int n,int matrix[m][n]) 
{
    int top=0,bottom=m-1;
    int left=0,right=n-1;
    while(top<=bottom && left<=right) 
    {
        // Traverse from Left to Right
        for(int i=left;i<=right;i++) 
        {
            printf("%d ",matrix[top][i]);
        }
        top++;

        // Traverse from Top to Bottom
        for (int i=top;i<=bottom;i++) 
        {
            printf("%d ",matrix[i][right]);
        }
        right--;

        // Traverse from Right to Left (if still valid)
        if(top<=bottom) 
        {
            for(int i=right;i>=left;i--)
            {
                printf("%d ",matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse from Bottom to Top (if still valid)
        if(left<=right) 
        {
            for(int i=bottom;i>=top;i--) 
            {
                printf("%d ",matrix[i][left]);
            }
            left++;
        }
    }
}

int main() {
    int m,n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&m,&n);
    int matrix[m][n];
    printf("Enter the elements of the matrix:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Matrix in Spiral Order will be:\n");
    spiral(m,n,matrix);
    return 0;
}