class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> areas;
        int ans = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            int start = i;
            while (!areas.empty() && areas.back().first > h) {
                int oldHeight = areas.back().first;
                int oldStart = areas.back().second;
                int width = i - oldStart;
                ans = max(ans, oldHeight * width);
                start = oldStart;
                areas.pop_back();
            }
            if (!areas.empty() && areas.back().first == h) {
                continue;
            }
            areas.push_back({h, start});
        }
        return ans;
    }
};