class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto a: nums){
            sum+=a;

        }
        if(sum%2 == 1)
            return false;

        int t = sum/2;
        vector<int> dp(t + 1, 0);
        dp[0] = 1;
        
        for(auto a: nums){
        
        for(int i = t; i>0; i--){
                if(i-a>=0 && dp[i-a]>0){
                    dp[i] = 1;
                }
            }
        }
        return dp[t];
        
    }
};
