class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int l = 2; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                for (int k = i + 1; k < j; k++) {
                    int curr = nums[i] * nums[k] * nums[j];
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + curr);
                }
            }
        }

        return dp[0][n - 1];
    }
};