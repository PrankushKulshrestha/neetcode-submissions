using vov = vector<vector<int>>;
class Solution {
   public:
    void dfs(vov& res, vector<int>& nums, int target, int sum, vector<int>& temp, int index) {
        if (sum == target) {
            res.push_back(temp);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (sum + nums[i] > target) break;
            temp.push_back(nums[i]);
            dfs(res, nums, target, sum + nums[i], temp, i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vov res;
        vector<int> temp;
        dfs(res, nums, target, 0, temp, 0);
        return res;
    }
};
