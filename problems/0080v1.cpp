/**
 * leetCode-0080-Remove Duplicates from Sorted Array II
 * 2017-03-10
 * Cpp version1
 */
#include<stdio.h>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
class Solution
{
public:
  int removeDuplicates(vector<int>& nums)
  {
    if(nums.size() <= 2)
      return nums.size();
    int index = 2;
    for(int i = 2;i < nums.size();i++)
    {
      if(nums[i] != nums[index-2])
        nums[index++] = nums[i];
    }
    return index;
  }
};
int main()
{
  freopen("in.txt", "r", stdin);
  vector<int> nums;
  int n;
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    nums.push_back(tmp);
  }
  Solution s;
  int result = s.removeDuplicates(nums);
  for(int i = 0;i < result;i++)
  {
    printf("%d ", nums[i]);
  }
  printf("size = %d\n", result);
}
