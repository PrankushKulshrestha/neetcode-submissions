class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int len = 1; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                for (int k = l; k <= r; k++) {
                    dp[l][r] = max(dp[l][r], nums[l - 1] * nums[k] * nums[r + 1] + dp[l][k - 1] + dp[k + 1][r]);
                }
            }
        }
        return dp[1][n];
    }
};
