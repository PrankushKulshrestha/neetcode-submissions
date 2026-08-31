class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> currSubset;
        vector<vector<int>> validSubsets;
        backtrack(0, nums, currSubset, validSubsets);
        return validSubsets;
    }
    void backtrack(int ind, vector<int>& nums, vector<int>& currSubset, vector<vector<int>>& validSubsets){
        validSubsets.push_back(currSubset);
        for(size_t i = ind; i < nums.size(); i++){
            if(i > ind && nums[i-1] == nums[i]){continue;}
            currSubset.push_back(nums[i]);
            backtrack(i+1, nums, currSubset, validSubsets);
            currSubset.pop_back();
        }
    }
};
