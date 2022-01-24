// https://leetcode.com/problems/spiral-matrix/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int sx = 0, sy = 0, ex = matrix.size() - 1, ey = matrix[0].size() - 1;
        vector<int> result(matrix.size() * matrix[0].size());
        int counter = 0, i, j;
        while (sx <= ex && sy <= ey)
        {
            for (j = sy; j <= ey; j++)
            {
                result[counter++] = matrix[sx][j];
            }
            sx++;

            for (i = sx; i <= ex; i++)
            {
                result[counter++] = matrix[i][ey];
            }
            ey--;

            if (sx <= ex)
            {
                for (j = ey; j >= sy; j--)
                {
                    result[counter++] = matrix[ex][j];
                }
                ex--;
            }

            if (sy <= ey)
            {
                for (i = ex; i >= sx; i--)
                {
                    result[counter++] = matrix[i][sy];
                }
                sy++;
            }
        }
        return result;
    }
};

int main()
{
}