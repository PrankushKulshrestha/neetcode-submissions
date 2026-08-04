class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            int l = 0;
            int t = k;
            for (int r = 0; r < n; r++) {
                if (s[r] != ch)
                    t--;
                while (t < 0) {
                    if (s[l] != ch)
                        t++;
                    l++;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};