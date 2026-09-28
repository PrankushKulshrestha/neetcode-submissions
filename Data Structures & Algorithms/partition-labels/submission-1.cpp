class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> count;

        for(auto c : s) count[c] += 1;

        vector<int> res;
        int curr_len = 0;
        unordered_map<char, int> subcount;
        for(int i = 0; i < s.size(); i++) {
            // cout<< curr_len << endl;
            if (i == 0) {
                subcount[s[i]] = 1;
                curr_len ++;
            }

            else {
                if (subcount.size() == 0) {
                    res.push_back(curr_len);
                    curr_len = 0;
                    subcount[s[i]] = 1;
                    curr_len = 1;
                }
                else {
                    subcount[s[i]] += 1;
                    curr_len++;
                }
            }

            if (subcount[s[i]] == count[s[i]]) subcount.erase(s[i]);
        }
        res.push_back(curr_len);
        return res;
    }
};
