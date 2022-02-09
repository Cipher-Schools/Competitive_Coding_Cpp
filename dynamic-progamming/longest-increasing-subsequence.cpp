// https://leetcode.com/problems/longest-increasing-subsequence
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums)
     {
          int size = nums.size();
          vector<int> dp(size, 1);
          int res = 1;
          for (int i = 1; i < size; ++i)
          {
               for (int j = 0; j < i; ++j)
               {
                    if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                    {
                         dp[i] = 1 + dp[j];
                    }
               }
               res = max(res, dp[i]);
          }
        return res;
     }
};

int main()
{
}