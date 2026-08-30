class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(vector<int>& nums, int target, int i) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (i == nums.size() || target < 0) {
            return;
        }
        curr.push_back(nums[i]);
        backtrack(nums, target - nums[i], i);
        curr.pop_back();

        backtrack(nums, target, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0);
        return ans;
    }
};
