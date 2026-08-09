class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int mn = *min_element(heights.begin(), heights.end());
        int mx = *max_element(heights.begin(), heights.end());
        map<int, int> mp;
        int ans = 0;
        for (int h = mn; h <= mx; h++) {
            int count = 0;
            int maxCount = 0;

            for (int i = 0; i < heights.size(); i++) {
                if (heights[i] >= h) {
                    count++;
                    maxCount = max(maxCount, count);
                } else {
                    count = 0;
                }
            }
            mp[h] = maxCount;
            int area = h * maxCount;
            if (area > ans) {
                ans = area;
            }
        }
        return ans;
    }
};