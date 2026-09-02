class Solution {
   public:
    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void func(vector<vector<string>>& ans, vector<string>& res, string& s, int idx) {
        if (idx == s.size()) {
            ans.push_back(res);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            string part = s.substr(idx, i - idx + 1);
            if (isPalindrome(part)) {
                res.push_back(part);
                func(ans, res, s, i + 1);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        func(ans, res, s, 0);
        return ans;
    }
};
