class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            auto it = find(nums.begin() + i + 1, nums.end(), target - nums[i]);

            if (it != nums.end()) {
                return {i, int(it - nums.begin())};
            }
        }
        return {};
    }
};