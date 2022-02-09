// https://leetcode.com/problems/minimum-path-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> costMatrix(row, vector<int>(col, 0));
        costMatrix[0][0] = grid[0][0];
        for (int j = 1; j < col; j++)
        {
            costMatrix[0][j] = costMatrix[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < row; i++)
        {
            costMatrix[i][0] = costMatrix[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                costMatrix[i][j] = grid[i][j] + min(costMatrix[i - 1][j], costMatrix[i][j - 1]);
            }
        }
        return costMatrix[row - 1][col - 1];
    }
};

int main()
{
}