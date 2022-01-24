// https://leetcode.com/problems/search-a-2d-matrix-ii
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int row = matrix.size() - 1;
        if (row < 0)
        {
            return false;
        }

        int c = matrix[0].size() - 1;
        int r = 0;
        while (c >= 0 && r <= row)
        {
            if (target == matrix[r][c])
            {
                return true;
            }
            else if (target < matrix[r][c])
            {
                c--;
            }
            else if (target > matrix[r][c])
            {
                r++;
            }
        }
        return false;
    }
};
int main()
{
}