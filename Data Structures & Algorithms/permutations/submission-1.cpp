class Solution {
public:
    vector<vector<int>> ans;
    void bt(vector<int> nums, int i) {
        if (i == nums.size()){
            ans.push_back(nums);
            return;
        }

        for (int a = i; a < nums.size(); ++a){
            swap(nums[a], nums[i]);
            bt(nums, i + 1);
            swap(nums[a], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        bt(nums, 0);
        return ans;
    }
};
