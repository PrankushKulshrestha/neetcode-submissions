class Solution {
public:
    double power(double b, long long e, double ans) {
        if(e<0) return 1/power(b, -e, ans);
        if(e == 0) return ans;
        if(e & 1) return power(b, e - 1, ans * b);
        return power(b * b, e / 2, ans);
    }

    double myPow(double x, int n) {
        return power(x, n, (double)1.0);
    }
};
