class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> a(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && st.top().second < temperatures[i]) {
                a[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push({i, temperatures[i]});
        }
        return a;
    }
};