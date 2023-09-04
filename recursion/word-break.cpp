bool wordBreak(string s, vector<string>& wordDict) {
    if (wordDict.size() == 0)
        return false;
    vector<bool> dp(s.size() + 1, false);
    set<string> dict(wordDict.begin(), wordDict.end());
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}
