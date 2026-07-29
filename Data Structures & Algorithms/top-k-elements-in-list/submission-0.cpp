class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<int> ans;
        while (k--) {
            int mx = 0, val = 0;
            for (auto &it : freq) {
                if (it.second > mx) {
                    mx = it.second;
                    val = it.first;
                }
            }
            ans.push_back(val);
            freq.erase(val);
        }
        return ans;
    }
};