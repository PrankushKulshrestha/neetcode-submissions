class Solution {
public:
    int countSubstrings(string s) {
        vector<int> p = manacher(s);
        int ans = 0;
        for (int i = 0; i < p.size(); i++) {
            ans += (p[i]+1)/2;
        }
        return ans;
    }

    vector<int> manacher(string &s) {
        if (s.size() == 0) return {};
        string t = "#" + string(1, s[0]);
        for (int i = 1; i < s.size(); i++) {
            t += "#" + string(1, s[i]);
        }
        t += "#";

        int n = t.size();
        vector<int> p(n, 0);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            p[i] = (i < r) ? min(r - i, p[l+(r-i)]) : 0;
            while (i-p[i]-1 >=0 && i+p[i]+1 < n && t[i-p[i]-1] == t[i+p[i]+1]) p[i]++;
            if (i+p[i] > r) {
                l = i-p[i];
                r = i+p[i];
            }
        }
        return p;
    }
};
