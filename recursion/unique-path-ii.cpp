// https://leetcode.com/problems/unique-paths-ii
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
     int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
     {
          int row = obstacleGrid.size();
          if (row == 0)
          {
               return 0;
          }
          int col = obstacleGrid[0].size();
          if (obstacleGrid[0][0]) {
             return 0;
          }
          vector<vector<int>> paths(row, vector<int>(col, 0));
          paths[0][0] = 1;
          for (int i = 1; i < row && obstacleGrid[i][0] == 0; i++)
          {
               paths[i][0] = 1;
          }

          for (int j = 1; j < col && obstacleGrid[0][j] == 0; j++)
          {
               paths[0][j] = 1;
          }

          for (int i = 1; i < row; i++)
          {
               for (int j = 1; j < col; j++)
               {
                    if (!obstacleGrid[i][j])
                    {
                         paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                    }
               }
          }
          return paths[row - 1][col - 1];
     }
};
int main()
{
}
