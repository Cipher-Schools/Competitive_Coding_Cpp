#include <bits/stdc++.h>
using namespace std;

int possibleMovesCount = 4;
int nextX[] = {1, 0, -1, 0};
int nextY[] = {0, 1, 0, -1};

class Solution
{
public:
    bool isSafe(vector<vector<bool>> &visited, int x, int y, const int R, const int C)
    {
        return (x >= 0 && x < R && y >= 0 && y < C && !visited[x][y]);
    }
    bool exist(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, const int R, const int C, int idx, string &word)
    {
        if (idx >= word.size())
        {
            return true;
        }
        else
        {
            visited[x][y] = true;
            for (int i = 0; i < possibleMovesCount; i++)
            {
                int nx = x + nextX[i];
                int ny = y + nextY[i];
                if (isSafe(visited, nx, ny, R, C) && word[idx] == board[nx][ny])
                {
                    if (exist(board, visited, nx, ny, R, C, idx + 1, word))
                        return true;
                }
            }
            visited[x][y] = false;
            return false;
        }
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word == "")
            return true;
        int R = board.size();
        int C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (board[i][j] == word[0] && exist(board, visited, i, j, 
                R, C, 1, word))
                    return true;
        return false;
    }
};