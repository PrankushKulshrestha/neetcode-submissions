class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> hold(n), sell(n), cool(n);
        hold[0] = -prices[0];
        sell[0] = 0;
        cool[0] = 0;
        for (int i = 1; i < n; ++i) {
            hold[i] = max(hold[i - 1], cool[i - 1] - prices[i]);
            sell[i] = hold[i - 1] + prices[i];
            cool[i] = max(cool[i - 1], sell[i - 1]);
        }
        return max(sell[n - 1], cool[n - 1]);
    }
};