// https://leetcode.com/problems/trapping-rain-water/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> lMax(n), rMax(n);
        lMax[0] = height[0];
        rMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
        {
            lMax[i] = max(height[i], lMax[i - 1]);
            rMax[n - i - 1] = max(height[n - i - 1], rMax[n - i]);
        }

        int res = 0;
        for (int i = 1; i < n - 1; i++)
        {
            res += min(lMax[i], rMax[i]) - height[i];
        }
        return res;
    }
};

int main()
{
}