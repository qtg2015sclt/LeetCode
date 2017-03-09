/**
 * leetCode-0026-Remove Duplicates from Sorted Array
 * 2017-03-09
 * Cpp version2
 */
#include<stdio.h>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
      return distance(nums.begin(), unique(nums.begin(), nums.end()));
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
