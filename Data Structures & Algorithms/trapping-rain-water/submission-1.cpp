class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i]);
        int leftMax = 0;
        int area = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] == 0 && leftMax == 0) continue;
            leftMax = max(leftMax, height[i]);
            int mn = min(leftMax, rightMax[i]);
            if (mn > height[i])
                area += mn - height[i];
        }
        return area;
    }
};