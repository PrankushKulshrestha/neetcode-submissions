class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> used(n, false);
        minDist[0] = 0;
        int totalCost = 0;
        for (int edges = 0; edges < n; edges++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (!used[i] && (u == -1 || minDist[i] < minDist[u])) {
                    u = i;
                }
            }
            used[u] = true;
            totalCost += minDist[u];
            for (int v = 0; v < n; v++) {
                if (!used[v]) {
                    int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], cost);
                }
            }
        }
        return totalCost;
    }
};
