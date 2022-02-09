// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#include <bits/stdc++.h>
using namespace std;

const int possibleMoves = 4;
const int xMoves[] = {1, -1, 0, 0};
const int yMoves[] = {0, 0, 1, -1};
class Solution
{
public:
    bool isSafe(vector<vector<bool>> &visited, int r, int c, int row, int col)
    {
        return !(r < 0 || c < 0 || r >= row || c >= col || visited[r][c]);
    }

    int longestIncreasingPath(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int x, int y, const int row, const int col, int &maxCounter, vector<vector<int>> &dp)
    {
        if (dp[x][y] > 0)
        {
            return dp[x][y];
        }
        visited[x][y] = true;
        int nextX, nextY, maxResult = 1;
        for (int i = 0; i < possibleMoves; i++)
        {
            nextX = x + xMoves[i];
            nextY = y + yMoves[i];
            if (isSafe(visited, nextX, nextY, row, col) && matrix[nextX][nextY] > matrix[x][y])
            {
                maxResult = max(maxResult, 1 + longestIncreasingPath(matrix, visited, nextX, nextY, row, col, maxCounter, dp));
            }
        }
        dp[x][y] = maxResult;
        visited[x][y] = false;
        maxCounter = max(maxCounter, maxResult);
        return maxResult;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        if (row == 0)
        {
            return 0;
        }
        int col = matrix[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> dp(row, vector<int>(col, 0));

        int maxCounter = 1;

        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                if (dp[r][c] == 0)
                    dp[r][c] = longestIncreasingPath(matrix, visited, r, c, row, col, maxCounter, dp);
            }
        }

        return maxCounter;
    }
};

int main()
{
}