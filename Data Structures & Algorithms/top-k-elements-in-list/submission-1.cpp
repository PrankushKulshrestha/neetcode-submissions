class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for (int i = nums.size(); i >= 1 && k > 0; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                k--;
                if (k == 0) break;
            }
        }
        return ans;
    }
};