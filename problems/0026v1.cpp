/**
 * leetCode-0026-Remove Duplicates from Sorted Array
 * 2017-03-09
 * Cpp version1
 */
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
      if(nums.empty())//坑。必须要判断。
        return 0;
      int index = 0;
      for(int i = 1;i < nums.size();i++)
      {
        if(nums[index] != nums[i])
          nums[++index] = nums[i];
      }
      //printf("index = %d\n", index);
      nums.resize(index+1);
      return nums.size();
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
  s.removeDuplicates(nums);
  //int result = s.removeDuplicates(nums);
  for(int i = 0;i < nums.size();i++)
  {
    printf("%d ", nums[i]);
  }
  printf("size = %lu\n", nums.size());
}
