// https://leetcode.com/problems/valid-sudoku/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
     bool isValidSudoku(vector<vector<char>> &board)
     {
          for (int i = 0; i < 9; i++)
          {
               bool hash1[10] = {}, hash2[10] = {};
               for (int j = 0; j < 9; j++)
               {
                    if (board[i][j] != '.')
                    {
                         if (hash1[board[i][j] - '0'])
                         {
                              return false;
                         }
                         else
                         {
                              hash1[board[i][j] - '0'] = true;
                         }
                    }
                    if (board[j][i] != '.')
                    {
                         if (hash2[board[j][i] - '0'])
                         {
                              return false;
                         }
                         else
                         {
                              hash2[board[j][i] - '0'] = true;
                         }
                    }
               }
          }
          for (int bsx = 0; bsx < 9; bsx += 3)
          {
               for (int bsy = 0; bsy < 9; bsy += 3)
               {
                    bool hash3[10] = {};
                    for (int i = bsx; i < bsx + 3; i++)
                    {
                         for (int j = bsy; j < bsy + 3; j++)
                         {
                              if (board[i][j] != '.')
                              {
                                   if (hash3[board[i][j] - '0'])
                                   {
                                        return false;
                                   }
                                   else
                                        hash3[board[i][j] - '0'] = true;
                              }
                         }
                    }
               }
          }

          return true;
     }
};
int main()
{
}
