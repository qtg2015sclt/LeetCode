81.Search in Rotated Sorted Array II

2017-03-16

- 本作品采用“Creative Commons 署名-非商业性使用-相同方式共享 3.0 Unported     
(cc by-nc-sa)”进行许可。http://creativecommons.org/licenses/by-nc-sa/3.0/
- 所有代码参考：[LeetCode题解，151道题完整版](https://github.com/soulmachine/leetcode)

### version 1:
- 33.Search in Rotated Sorted Array的进阶
- 因为允许重复，会出现first位和mid位数字虽然相等、但这个区间并非递增的情况，所以要单独拿出来判断一下
```c++
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
```

### 分析：
- 时间复杂度是多少呢？最坏的情况下，应该是O(n)的， 形如：1 1 1 1 1 1 3（个人看法，欢迎指正）

-FIN-
