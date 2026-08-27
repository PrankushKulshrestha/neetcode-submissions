class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> bucket(2001);
        for(auto &num : nums){
            bucket[num + 1000]++;
        }
        for(int i = 2000; i>=0;i--){
            if(k <= bucket[i]){
                return i-1000;
            }
            k -= bucket[i];
        }
        return -1;
    }
};
