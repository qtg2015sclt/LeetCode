/**
 * leetCode-0081-Search in Rotated Sorted Array II
 * 2017-03-16
 * Cpp version1
 */
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
      int first = 0, last = nums.size();
      while(first != last)
      {
        int mid = first + (last - first) / 2;
        if(nums[mid] == target)
          return true;
        if(nums[first] < nums[mid])
        {
          if(nums[first] <= target && target < nums[mid])
            last = mid;
          else
            first = mid+1;
        }
        else if(nums[first] > nums[mid])
        {
          if(nums[mid] < target && target <= nums[last-1])
            first = mid+1;
          else
            last = mid;
        }
        else//nums[first] == nums[mid]
        {
          first++;
        }
      }
      return false;
    }
};
int main()
{
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  Solution s;
  int result = s.search(nums, 9);
  cout << result << endl;
}
