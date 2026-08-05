class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        vector<int> need(128, 0);
        for (char c : t) need[c]++;
        int left = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;
        for (int right = 0; right < s.size(); right++) {
            if (need[s[right]] > 0) count--;
            need[s[right]]--;
            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                need[s[left]]++;
                if (need[s[left]] > 0) count++;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};