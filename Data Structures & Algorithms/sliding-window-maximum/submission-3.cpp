class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = k - 1;
        vector<int> ans;
        int mx_pos = max_element(nums.begin(), nums.begin() + k) - nums.begin();
        int mx = nums[mx_pos];
        ans.push_back(mx);
        while (right < nums.size() - 1) {
            right++;
            if (nums[right] >= mx) {
                mx_pos = right;
                mx = nums[right];
            }
            if (left == mx_pos) {
                mx_pos = max_element(nums.begin() + left + 1, nums.begin() + left + k + 1) -
                         nums.begin();
                mx = nums[mx_pos];
            }
            left++;
            ans.push_back(mx);
        }
        return ans;
    }
};
