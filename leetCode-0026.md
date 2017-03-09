26.Remove Duplicates from Sorted Array

2017-03-09

- 一开始连题目意思都理解错了……题意是「连续」的重复数字保留一个，不是所有重复的数字中保留一个，因为这个array已经是sorted了，所以说注意审题很重要。
- 本作品采用“Creative Commons 署名-非商业性使用-相同方式共享 3.0 Unported     
(cc by-nc-sa)”进行许可。http://creativecommons.org/licenses/by-nc-sa/3.0/ （第一次用这个，不知道是不是用错了……请指教QAQ)
- 所有代码参考：[LeetCode题解，151道题完整版](https://github.com/soulmachine/leetcode)

#### version 1:
- 做了一点小小的更改，用index+1把nums给resize了一下，其实不用也可以，直接返回index+1就行
```c++
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
```

#### version 2:
- distance在iterator这个头文件中（查了一下，好像algorithm里也有），用来计算参数1到参数2之间包含的元素个数
  - 示例：distance(nums.begin(), nums.end());所以应该是左闭右开区间的个数
- unique在algorithm中，基本上和version1中的实现差不多意思，并且返回处理得到的最后一个元素的后一个位置（这样就很方便嵌套用）
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
      return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
};
```

#### version 3:
- 我的理解：在类里又写了一个函数模板，还是重载的，参数是first（第一个元素的位置）、last（最后一个元素的后一个位置），以及一个用来返回的位置（先置在第一个位置上，返回的时候实际上是指向处理后的元素集的最后一个元素的后一个位置， 这样也是方便嵌套在distance里，这应该是一个套路吧）
- upper_bound应该是在一个给定的区间里返回如下位置：第一次比某给定值要大的那个元素的位置
```c++
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
```

#### 分析：
- 时间复杂度都是O(n)，要求原地处理，所以空间复杂度是O(1)
- 后两个使用了STL，最后一个是写了一个重载函数，利用了upper_bound
- 实际在线运行的情况是依次更快的，目前还没想明白为什么

-FIN-
