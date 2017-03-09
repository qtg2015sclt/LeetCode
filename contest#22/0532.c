/**
 * leetCode-0532-K-diff Pairs in an Array
 * 2017-03-05
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<stdlib.h>
int cmp (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int findPairs(int* nums, int numsSize, int k)
{
  int result = 0;
  qsort(nums, numsSize, sizeof(int), cmp);
  // for(int i = 0;i < numsSize;i++)
  // {
  //   printf("%d ", nums[i]);
  // }
  for(int i = 0;i < numsSize-1;i++)
  {
    int j = i+1;
    while(j < numsSize-1 && nums[j] == nums[j+1])
      j++;
    //printf("j = %d\n", j);
    for(;j < numsSize;j++)
    {
      if(abs(nums[i] - nums[j]) == k)
      {
        result++;
        break;
      }
    }
    while(i < numsSize-1 && nums[i] == nums[i+1])
      i++;
  }
  return result;
}
int main()
{
  int nums[] = {1, 1};
  int k = 0;
  int result = findPairs(nums, 2, k);
  printf("%d\n", result);
}
