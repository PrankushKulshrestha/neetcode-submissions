class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        vector<int> freq1(26, 0), freq2(26, 0);
        for (char ch : s1)
            freq1[ch - 'a']++;
        int left = 0;
        for (int right = 0; right < m; right++) {
            freq2[s2[right] - 'a']++;
            if (right - left + 1 > n) {
                freq2[s2[left] - 'a']--;
                left++;
            }
            if (right - left + 1 == n && freq1 == freq2)
                return true;
        }
        return false;
    }
};