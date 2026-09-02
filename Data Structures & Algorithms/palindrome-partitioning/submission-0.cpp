class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void dfs(const string& s, int l) {
        if (l == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int r = l; r < s.size(); r++) {
            if (isPalindrome(s, l, r)) {
                temp.push_back(s.substr(l, r - l + 1));
                dfs(s, r + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};
