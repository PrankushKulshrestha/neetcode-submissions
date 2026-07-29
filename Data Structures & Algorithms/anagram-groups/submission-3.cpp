class Solution {
public:
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t hash = 0;
            for (int x : v) {
                hash = hash * 31 + x;
            }
            return hash;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHash> mp;
        for (string& s : strs) {
            vector<int> freq(26, 0);
            for (char c : s)
                freq[c - 'a']++;
            mp[freq].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& it : mp)
            ans.push_back(it.second);
        return ans;
    }
};