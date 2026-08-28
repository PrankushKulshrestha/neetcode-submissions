class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) freq[c - 'A']++;
        int maxf = *max_element(freq.begin(), freq.end());
        int numMax = count(freq.begin(), freq.end(), maxf);
        return max((int)tasks.size(), (maxf - 1) * (n + 1) + numMax);
    }
};