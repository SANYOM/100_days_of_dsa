/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

#include<stdio.h>
#include<stdlib.h>

int* twoSum(int*, int, int, int*);

int main()
{
    int size,target;
    int returnsize;

    printf("Enter the size of the array: ");

    scanf("%d",&size);
    int nums[size];

    printf("Enter the elements of the array:\n");

    for(int i=0;i<size;i++){
        scanf("%d",&nums[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d",&target);

    int* arr=twoSum(nums,size,target,&returnsize);

    if(arr != NULL) 
    {
        for(int i=0; i<returnsize; i++) 
        {
            printf("%d ", arr[i]);
        }
        free(arr);
    } 
    else 
    {
        printf("No solution found\n");
    }
    return 0;
    
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int* p = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;  
    
    for (int i = 0; i < numsSize; i++) 
    {
        for (int j = i + 1; j < numsSize; j++) 
        {  
            if (nums[i] + nums[j] == target) 
            {
                p[0] = i;
                p[1] = j;
                return p;
            }
        }
    }
    free(p);
    return NULL;
}
