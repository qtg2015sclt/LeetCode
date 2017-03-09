/**
 * leetCode-0001-Two Sum
 * 2017-03-05
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
  int *result = (int*)malloc(2*sizeof(int));
  for(int i = 0;i < numsSize-1;i++)
  {
    for(int j = i+1;j < numsSize;j++)
    {
      if(target == nums[i] + nums[j])
      {
        *result = i;
        *(result+1) = j;
        return result;
      }
    }
  }
  return result;
}
int main()
{
  int nums[] = {2, 7, 11, 15};
  int *result = (int*)malloc(2*sizeof(int));
  result = twoSum(nums, 4, 9);
  printf("%d %d\n", *result, *(result+1));
  free(result);
}
