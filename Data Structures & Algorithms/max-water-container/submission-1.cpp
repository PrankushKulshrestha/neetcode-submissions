class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i =0;
        int j = nums.size()-1;
        int maxArea = 0;
        while(i<=j){
            int w = j-i;
            int h = min(nums[i],nums[j]);
            int area = w*h;
            maxArea = max(maxArea,area);
            if(nums[i]<nums[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};