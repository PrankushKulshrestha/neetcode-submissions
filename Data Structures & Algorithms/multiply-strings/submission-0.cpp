class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.size(), m = num2.size();
        vector<int> res(n + m);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int p = i + j + 1;
                int mul = (num1[i] - '0') * (num2[j] - '0') + res[p];
                res[p] = mul % 10;
                res[p - 1] += mul / 10;
            }
        }
        string ans;
        int i = 0;
        while (i < res.size() && res[i] == 0) i++;
        while (i < res.size()) ans += char(res[i++] + '0');
        return ans;
    }
};
