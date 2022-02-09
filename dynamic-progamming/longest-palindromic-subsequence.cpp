#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int len = s.length();
        if (len <= 1)
        {
            return len;
        }
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int window, i, j;
        for (i = 0; i < len; i++)
        {
            dp[i][i] = 1;
        }

        for (window = 2; window <= len; window++)
        {
            for (i = 0; i < len - window + 1; i++)
            {
                j = i + window - 1;
                if (window == 2)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 2;
                    }
                    else
                    {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
                else
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][len - 1];
    }
};

int main()
{
}