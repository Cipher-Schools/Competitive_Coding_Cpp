// https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size();
        vector<bool> rowIndex(row);
        vector<bool> colIndex(col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowIndex[i] = true;
                    colIndex[j] = true;
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            if (rowIndex[i])
            {
                for (int j = 0; j < col; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < col; j++)
        {
            if (colIndex[j])
            {
                for (int i = 0; i < row; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
}