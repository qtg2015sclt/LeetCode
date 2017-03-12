#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k)
    {
      int len = s.length();
      //cout << "length = " << len << endl;
      for(int i = 0;i < len;i += 2*k)
      {
        if(i + 2*k < len || i + k <= len)
        {
          //cout << "i = " << i << ", k = " << k << endl;
          reverse(s.begin()+i, s.begin()+i+k);
        }
        else
          reverse(s.begin()+i, s.end());
      }
      return s;
    }
};
int main()
{
  string str = "";
  int k = 3;
  Solution s;
  string result = s.reverseStr(str, k);
  cout << result << endl;
}
