int change(int S, vector<int>& coins) {
        int N = coins.size();
        vector<int> dp(S + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int s = 1; s <= S; s++) {
                if (s >= coins[i - 1]) {
                    dp[s] = dp[s] + dp[s - coins[i - 1]];
                }
            }
        }
        return dp[S];
    }
