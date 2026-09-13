class Solution {
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        auto lambda = [](const vector<int>& a, const vector<int>& b) {
            return a.front() > b.front();
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(lambda)> pq(lambda);
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        visited[0][0] = true;
        pq.push(vector<int>{grid[0][0], 0, 0});

        while (!pq.empty()) {
            vector<int> current = pq.top();
            int e = current[0], r = current[1], c = current[2];
            pq.pop();

            if (r == n - 1 && c == n - 1)
                return e;
            
            for (vector<int> dir: dirs) {
                int nr = r + dir[0], nc = c + dir[1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) continue;

                visited[nr][nc] = true;
                pq.push(vector<int>{ max(e, grid[nr][nc]), nr, nc });
            }
        }
        return 0;
    }
};
