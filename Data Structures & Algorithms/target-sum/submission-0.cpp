class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum || (sum + target) % 2) return 0;
        int need = (sum + target) / 2;
        vector<int> dp(need + 1);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = need; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        return dp[need];
    }
};
