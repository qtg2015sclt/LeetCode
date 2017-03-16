33.Search in Rotated Sorted Array

2017-03-16

- 直接搜应该也可以，但既然是有序的，大约是可以利用一下二分法
- 关键就是二分法怎么在这种特殊的情况下进行改进
- 本作品采用“Creative Commons 署名-非商业性使用-相同方式共享 3.0 Unported     
(cc by-nc-sa)”进行许可。http://creativecommons.org/licenses/by-nc-sa/3.0/
- 所有代码参考：[LeetCode题解，151道题完整版](https://github.com/soulmachine/leetcode)

#### version 1:
- 和普通二分法不同的地方：mid位置不是目标元素时，两种可能：
  1. 4 5 6 7 0 1 2这种，绕支点旋转过后的有序数组的前半部分较长，又有两种可能：
    1. 目标元素就在first和mid之间，更新last
    2. 目标元素不在first和mid之间，更新first
  2. 5 6 7 0 1 2 4这种，绕支点旋转过后的有序数组的后半部分较短，两种可能：
    1. 目标元素在mid和last之间，更新first
    2. 目标元素不在mid和last之间，更新last
- 要注意的一点是last是最后一个元素的后一个位置
```c++
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
```

#### 分析：
- 时间复杂度是O(logn)，空间复杂度O(1)
- 难点在于目标元素不在mid位置时如何更新边界

-FIN-
