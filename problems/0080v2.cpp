/**
 * leetCode-0080-Remove Duplicates from Sorted Array II
 * 2017-03-10
 * Cpp version2
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
    const int n = nums.size();
    int index = 0;
    for(int i = 0;i < n;i++)
    {
      if(i > 0 && i < n-1 && nums[i] == nums[i-1] && nums[i] == nums[i+1])
        continue;
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
