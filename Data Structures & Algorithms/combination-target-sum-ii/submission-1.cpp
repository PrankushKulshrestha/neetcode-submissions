class Solution {
public:
    void f(int idx,
           vector<int>& nums,
           int target,
           vector<int>& temp,
           vector<vector<int>>& ans)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            if (nums[i] > target)
                break;
            temp.push_back(nums[i]);
            f(i + 1, nums, target - nums[i], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, nums, target, temp, ans);
        return ans;
    }
};
