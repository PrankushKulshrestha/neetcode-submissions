class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int res = 0, curr = nums[0], cnt = 0, i = 0;
        while(i < nums.size()){
            if(curr != nums[i]){
                curr = nums[i];
                cnt=0;
            }
            while(i<nums.size() && nums[i] == curr){
                i++;
            }
            cnt++;
            curr++;
            res = max(res,cnt);
        }
        return res;
    }
};
