class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for(auto i : nums){
            if (count(nums.begin(), nums.end(), i)>1){
                return true;
            }
        }
        return false;
    }
};