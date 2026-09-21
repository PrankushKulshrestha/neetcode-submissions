class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        vector<pair<int, int>> dp(n + 1, make_pair(0, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            int buy = dp[i + 1].second - prices[i];
            int cooldown = dp[i + 1].first;
            dp[i].first = max(buy, cooldown);

            int sell = (i + 2) < n ? dp[i + 2].first + prices[i] : prices[i];
            cooldown = dp[i + 1].second;
            dp[i].second = max(sell, cooldown);
        }
        return dp[0].first;
    }
};
