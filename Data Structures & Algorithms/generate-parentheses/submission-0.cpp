class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        function<void(int, int)> backtrack = [&](int open, int close) {
            if (cur.size() == 2 * n) {
                res.push_back(cur);
                return;
            }
            if (open < n) {
                cur.push_back('(');
                backtrack(open + 1, close);
                cur.pop_back();
            }
            if (close < open) {
                cur.push_back(')');
                backtrack(open, close + 1);
                cur.pop_back();
            }
        };
        backtrack(0, 0);
        return res;
    }
};
