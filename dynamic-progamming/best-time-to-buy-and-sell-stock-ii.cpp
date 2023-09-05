int maxProfit(vector<int>& prices) {
    int N = prices.size();
    if (N <= 1)
        return 0;
    int i = 0, j, profit = 0;
    while (i < N) {
        while (i < N - 1 && prices[i] >= prices[i + 1]) {
            i++;
        }
        if (i >= N - 1)
            break;
        j = i;
        while (i < N - 1 && prices[i] <= prices[i + 1]) {
            i++;
        }
        if (i < N) {
            profit += (prices[i] - prices[j]);
        } else {
            profit += (prices[N - 1] - prices[j]);
        }
    }
    return profit;
}
