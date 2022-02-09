#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int l1 = text1.length(), l2 = text2.length();
        if (l1 == 0 || l2 == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[l1][l2];
    }
};

int main()
{
    string a = "AGGTAB";
    string b = "GXTXAYB";
    return 0;
}