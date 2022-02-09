#include <bits/stdc++.h>
using namespace std;

int knapsack(int capacity, const vector<int> &W, const vector<int> &V)
{
    int N = W.size();

    vector<vector<int>> dp(N + 1, vector<int>(capacity + 1));
    for (int i = 1; i <= N; i++)
    {

        int w = W[i - 1], v = V[i - 1];
        for (int sz = 1; sz <= capacity; sz++)
        {
            dp[i][sz] = dp[i - 1][sz];
            if (sz >= w && dp[i - 1][sz - w] + v > dp[i][sz])
                dp[i][sz] = dp[i - 1][sz - w] + v;
        }
    }

    int sz = capacity;
    vector<int> itemsSelected;
    for (int i = N; i > 0; i--)
    {
        if (dp[i][sz] != dp[i - 1][sz])
        {
            int itemIndex = i - 1;
            itemsSelected.push_back(itemIndex);
            sz -= W[itemIndex];
        }
    }

    return dp[N][capacity];
}
int main()
{
    return 0;
}