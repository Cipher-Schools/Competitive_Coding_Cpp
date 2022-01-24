// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int row = matrix.size();
        int lo = matrix[0][0], hi = matrix[row - 1][row - 1] + 1, mid, count, temp;

        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2, temp = row - 1, count = 0;

            // For each row, we count the elements that are smaller then mid
            for (int i = 0; i < row; i++)
            {
                while (temp >= 0 && matrix[i][temp] > mid)
                    temp--;
                count += temp + 1;
            }

            if (count < k)
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }
};

int main()
{
}