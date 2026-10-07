class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                res[i] = res[i-1] + 1;
            } else {
                res[i] = res[i/2];
            }
        }

        return res;
    }
};
