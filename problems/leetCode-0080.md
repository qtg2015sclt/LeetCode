80.Remove Duplicates from Sorted Array II

2017-03-10

- 本作品采用“Creative Commons 署名-非商业性使用-相同方式共享 3.0 Unported     
(cc by-nc-sa)”进行许可。http://creativecommons.org/licenses/by-nc-sa/3.0/
- 所有代码参考：[LeetCode题解，151道题完整版](https://github.com/soulmachine/leetcode)

#### version1
- 每个数和自己之前隔一个的数相比较，是因为每个数最多出现两次。如果和自己之前隔一个的数相同，说明这已经至少是第三次出现这个数了应该跳过
```c++
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
```

#### version2
- 每次和前驱及后继比较，如果都相同说明此数出现了超过两次以上，跳过当前数；只有不同时和前驱及后继相同时才是本题合法的数据。很巧妙
- 使用const int n来保存容器的大小是很好的做法，这样不用每次判断循环的时候都调用一次nums.size()，减少了耗时（应该是吧……）；且不会因为误操作修改n
```c++
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
```

#### 分析：
- 时间复杂度都是O(n)，额外空间是常数个O(1)
- v1扩展性更好（比如要求最多出现三次时），但v2比v1要更快一点，why_(:зゝ∠)_

-FIN-
