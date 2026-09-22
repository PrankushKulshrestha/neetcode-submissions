class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        if (abs(target) > total_sum || (target + total_sum) % 2 != 0) {
            return 0;
        }
        int tar = (target + total_sum) / 2;
        vector<int> dp(tar + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = tar; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        return dp[tar];
    }
};
