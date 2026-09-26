class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        int c=0;
        int p=0;
        int m=0;
        for(int i=0;i<n-1;i++)
        {
            m = max(m,i+nums[i]);
            if(i==p)
            {
                c++;
                p=m;
            }
        }
        return c;  
    }
};
