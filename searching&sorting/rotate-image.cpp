// https://leetcode.com/problems/rotate-image/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 1)
        {
            return;
        }
        int i, j, k;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (i = 0; i < n; i++)
        {
            j = 0, k = n - 1;
            while (j < k)
            {
                swap(matrix[i][j], matrix[i][k]);
                j++;
                k--;
            }
        }
    }
};

int main()
{
}