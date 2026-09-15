class Solution {
private:
    int robHelper(vector<int>& nums, int start, int end) {
        
        if (end - start <= 1) return nums[start];

        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start+1]);

        for (int i = start+2; i < end; i++) {
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        int rob1 = robHelper(nums, 0, n-1);
        int rob2 = robHelper(nums, 1, n);

        return max(rob1, rob2);
    }
};
