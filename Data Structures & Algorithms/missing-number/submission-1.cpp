class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = 0;
        for(auto it : nums) 
        {
            sum+=it;
            n = max(n,it);
        }
        n = nums.size();
        int ans = n*(n+1);
        ans = ans/2;
        ans = ans - sum;
        // if()
        return ans;
    }
};
