class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 0, suf = 0;
        int res = nums[0];
        for(int i=0;i<n;++i)
        {
            pre=nums[i]*(pre==0?1:pre);
            suf=nums[n-i-1]*(suf==0?1:suf);
            res=max(res, max(pre, suf));
        }
        return res;
    }
};
