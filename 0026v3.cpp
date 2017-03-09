/**
 * leetCode-0026-Remove Duplicates from Sorted Array
 * 2017-03-09
 * Cpp version3
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
      return distance(nums.begin(), removeDuplicates(nums.begin(), nums.end(), nums.begin()));
    }
    template<typename InIt, typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output)
    {
      while(first != last)
      {
        *output++ = *first;
        first = upper_bound(first, last, *first);
      }
      return output;
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
