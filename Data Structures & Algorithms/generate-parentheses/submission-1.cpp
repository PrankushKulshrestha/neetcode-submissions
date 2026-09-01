class Solution {
public:
    vector<string> ans;
    string curr;
    void generate(int n, int open, int end) {
        if(curr.length() == 2*n) {
            ans.push_back(curr);
            return;
        }
        if(open < n) {
            curr.push_back('(');
            generate(n, open + 1, end);
            curr.pop_back();
        }
        if(end < open) {
            curr.push_back(')');
            generate(n, open, end + 1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        curr = "";
        ans = {};
        generate(n, 0, 0);
        return ans;
    }
};
