// https://leetcode.com/problems/jump-game
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int size = nums.size();
        if (size <= 1)
            return true;
        if (size > 1 && nums[0] == 0)
            return false;
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && nums[j] + j >= i)
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[size - 1];
    }
};