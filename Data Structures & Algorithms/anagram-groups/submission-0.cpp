class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        vector<vector<string>> ans(1);
        vector<unordered_map<char, int>> chr;
        ans[0].push_back(strs[0]);
        unordered_map<char, int> first;
        for (int i = 0; i < strs[0].size(); i++) {
            first[strs[0][i]]++;
        }
        chr.push_back(first);
        if (strs.size() == 1) return ans;
        for (int i = 1; i < strs.size(); i++) {
            unordered_map<char, int> chk;
            for (int j = 0; j < strs[i].size(); j++) {
                chk[strs[i][j]]++;
            }
            auto it = find(chr.begin(), chr.end(), chk);
            if (it == chr.end()) {
                chr.push_back(chk);
                ans.push_back({strs[i]});
            } else {
                int index = it - chr.begin();
                ans[index].push_back(strs[i]);
            }
        }
        return ans;
    }
};