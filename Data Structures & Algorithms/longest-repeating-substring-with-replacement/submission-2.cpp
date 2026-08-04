class Solution {
public:
    int characterReplacement(string s, int k) {
        int a[26] = {0};
        int l = 0, r = 0, n = s.size(), mx = 0, res = 0;
        while (r < n) {
            a[s[r] - 'A']++;
            mx = max(mx, a[s[r] - 'A']);
            while (r - l + 1 - mx > k) {
                a[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};