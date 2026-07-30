class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int nzprod = 1;
        for (int x : nums) {
            prod *= x;
            if (x != 0) {
                nzprod *= x;
            }
        }
        if (count(nums.begin(), nums.end(), 0) > 1) {
            vector<int> output(nums.size(), 0);
            return output;
        }
        vector<int> output(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                output[i]=nzprod;
                continue;
            }
            output[i] = prod / nums[i];
        }
        return output;
    }
};