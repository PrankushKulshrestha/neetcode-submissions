class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (const string &s : strs) {
            vector<int> freq(26, 0);
            for (char ch : s) {
                freq[ch - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#" + to_string(freq[i]);
            }
            hash[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &[key, group] : hash) {
            ans.push_back(group);
        }
        return ans;
    }
};