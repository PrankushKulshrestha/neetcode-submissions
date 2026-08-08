class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            int cur = temperatures[i];
            int jump = i + 1;
            while (jump < n) {
                if (cur < temperatures[jump]) {
                    res[i] = jump - i;
                    break;
                }
                if (res[jump] == 0)
                    break;
                jump += res[jump];
            }
        }
        return res;
    }
};