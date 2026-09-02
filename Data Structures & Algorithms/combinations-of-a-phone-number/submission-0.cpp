class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void dfs(string& digits, int idx, list<char>& temp) {
        if (idx == digits.size()) {
            string res(temp.begin(), temp.end());
            ans.push_back(res);
            return;
        }
        string letters = mp[digits[idx] - '0'];
        for (char c : letters) {
            temp.push_back(c);
            dfs(digits, idx + 1, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        list<char> temp;
        dfs(digits, 0, temp);
        return ans;
    }
};
