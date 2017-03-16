/**
 * leetCode-0033-Search in Rotated Sorted Array
 * 2017-03-16
 * Cpp version1
 */
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
  int search(vector<int>& nums, int target)
  {
    int first = 0, last = nums.size();
    while(first != last)
    {
      const int mid = first + (last - first) / 2;
      if(nums[mid] == target)
        return mid;
      if(nums[first] <= nums[mid])
      {
        if(nums[first] <= target && target < nums[mid])
          last = mid;//要注意last事实上是最后一个元素的后一个位置，所以并不是mid-1
        else
          first = mid+1;
      }
      else
      {
        if(nums[mid] < target && target <= nums[last-1])
          first = mid+1;
        else
          last = mid;
      }
    }
    return -1;
  }
};
int main()
{
  vector<int> nums;
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(7);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  Solution s;
  int result = s.search(nums, 8);
  cout << result << endl;
}
