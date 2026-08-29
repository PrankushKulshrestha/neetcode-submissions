class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        f(nums, ans, curr, 0);
        return ans;
    }

    void f(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int i) {
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        f(nums, ans, curr, i+1);
        curr.pop_back();
        f(nums, ans, curr, i+1);
    }
};
