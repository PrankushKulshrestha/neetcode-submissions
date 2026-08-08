class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = speed.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < speed.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        stack<float> st;
        int n = cars.size();
        st.push((float)(target - cars[n - 1].first) / cars[n - 1].second);
        for (int i = n - 2; i > -1; i--) {
            if ((float)(target - cars[i].first) / cars[i].second <= st.top()) {
                ans--;
            } else {
                st.pop();
                st.push((float)(target - cars[i].first) / cars[i].second);
            }
        }
        return ans;
    }
};