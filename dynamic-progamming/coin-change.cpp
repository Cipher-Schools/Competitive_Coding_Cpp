#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int size = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int a = 1; a <= amount; a++)
        {
            for (int j = 1; j <= size; j++)
            {
                if (a >= coins[j - 1])
                {
                    dp[a] = min(dp[a], (dp[a - coins[j - 1]] == INT_MAX ? INT_MAX : 1 + dp[a - coins[j - 1]]));
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main()
{
    return 0;
}