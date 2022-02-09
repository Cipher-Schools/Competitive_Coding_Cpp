// https://leetcode.com/problems/longest-palindromic-substring/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
        {
            return s;
        }
        string result;
        int len = s.length(), maxLen = 0;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = 1;
            if (maxLen < dp[i][i])
            {
                maxLen = 1;
                result = s.substr(i, i - i + 1);
            }
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
                        if (maxLen < window)
                        {
                            maxLen = window;
                            result = s.substr(i, window);
                        }
                    }
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] > 0)
                    {
                        dp[i][j] = window;
                        if (maxLen < window)
                        {
                            maxLen = window;
                            result = s.substr(i, window);
                        }
                    }
                }
            }
        }

        return result;
    }
};