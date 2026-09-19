class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > dp.back())
                dp.push_back(nums[i]);
            else{
                int l = 0; 
                int r = dp.size() - 1;
                int idx = 0;
                while(l <= r){
                    int mid = (l + r)/2;
                    if(dp[mid] >= nums[i]){
                        idx = mid;
                        r = mid - 1;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                dp[idx] = nums[i];
            }
        }
        return dp.size();
    }

};
