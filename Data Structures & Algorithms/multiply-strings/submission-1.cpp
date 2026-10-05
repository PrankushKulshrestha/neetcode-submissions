class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> res(n + m);

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j --){
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');  
            }
        }
        int carry = 0;
        for(int i = n + m - 1; i >= 0; i--){
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
        }
        for(int i = 0; i < n + m; i++){
            cout << res[i] << ' ';
        }
        int start = 0;
        while(start < n + m && res[start] == 0) start++;
        if(start == n + m) return "0";
        string ret = "";
        while(start < n + m) ret += res[start++] + '0';
        return ret;
    }
};
