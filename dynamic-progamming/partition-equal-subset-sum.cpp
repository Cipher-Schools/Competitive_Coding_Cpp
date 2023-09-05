int subsetSumPossible(vector<int> &nums, int S) {
    int N = nums.size();
    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    for (int i = 0; i <= N; i++)
        dp[i][0] = true;

    for (int i = 1; i <= N; i++) {
        for (int s = 1; s <= S; s++) {

            if (s >= nums[i - 1]) {
                dp[i][s] = dp[i - 1][s] || dp[i - 1][s - nums[i - 1]]; // Include
            } else {
                dp[i][s] = dp[i - 1][s]; // Not included
            }
        }
    }
    return dp[N][S];
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num: nums) {
        sum += num;
    }
    if (sum & 1) {
        return false;
    } else {
        return subsetSumPossible(nums, sum / 2);
    }
}
