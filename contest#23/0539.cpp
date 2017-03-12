#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints)
    {
      int result = 24*60;
      int size = timePoints.size();
      int hs[1450] = {0};
      for(int i = 0;i < size;i++)
      {
        int nowTime = convert2Minutes(timePoints[i]);
        //cout << "nowTime = " << nowTime << endl;
        if(hs[nowTime] == 1)//特殊判断
          return 0;
        else
          hs[nowTime] = 1;
      }
      for(int i = 0;i < 1450;i++)
      {
        if(hs[i] == 1)
        {
          for(int j = i+1;j < 1450;j++)
          {
            if(hs[j] == 1 && min(abs(i-j), 1440-abs(i-j)) < result)
            {
              //cout << "i = " << i << ", j = " << j << endl;
              result = min(abs(i-j), 1440-abs(i-j));
              //cout << abs(i-j) << ", " << 1440-abs(i-j) << endl;
              //cout << "result = " << result << endl;
            }
          }
        }
      }
      return result;
    }
    int convert2Minutes(string s)
    {
      return ((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
    }
};
int main()
{
  vector<string> timePoints;
  // timePoints.push_back("00:00");
  // timePoints.push_back("23:59");
  // timePoints.push_back("00:00");
  timePoints.push_back("05:31");
  timePoints.push_back("22:08");
  timePoints.push_back("00:35");
  Solution s;
  int result = s.findMinDifference(timePoints);
  cout << result << endl;
}
