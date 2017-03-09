/**
 * leetCode-0531-Lonely Pixel I
 * 2017-03-05
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int findLonelyPixel(char** picture, int pictureRowSize, int pictureColSize)
{
  int result = 0;
  int numOfBlackRow[pictureRowSize];
  int numOfBlackCol[pictureColSize];
  for(int i = 0;i < pictureRowSize;i++)
  {
    numOfBlackRow[i] = 0;
  }
  for(int i = 0;i < pictureColSize;i++)
  {
    numOfBlackCol[i] = 0;
  }
  for(int i = 0;i < pictureRowSize;i++)
  {
    for(int j = 0;j < pictureColSize;j++)
    {
      if(picture[i][j] == 'B')
      {
        numOfBlackRow[i]++;
        numOfBlackCol[j]++;
      }
    }
  }
  for(int i = 0;i < pictureRowSize;i++)
  {
    for(int j = 0;j < pictureColSize;j++)
    {
      if(picture[i][j] == 'B' && numOfBlackRow[i] == 1 && numOfBlackCol[j] == 1)
      {
        result++;
      }
    }
  }
  return result;
}
int main()
{
  char *picture[3] = {"WWB", "WBW", "BWW"};
  int result = findLonelyPixel(picture, 3, 3);
  printf("%d\n", result);
}
