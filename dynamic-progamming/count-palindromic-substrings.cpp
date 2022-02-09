// https://leetcode.com/problems/palindromic-substrings/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        if (s.length() <= 1)
        {
            return s.length();
        }
        int result = 0;
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = 1;
            result += 1;
        }

        int i, j;
        for (int window = 2; window <= len; window++)
        {
            for (int i = 0; i < len - window + 1; i++)
            {
                j = i + window - 1;
                if (window == 2)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = window;
                        result += 1;
                    }
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] > 0)
                    {
                        dp[i][j] = window;
                        result += 1;
                    }
                }
            }
        }

        return result;
    }
};