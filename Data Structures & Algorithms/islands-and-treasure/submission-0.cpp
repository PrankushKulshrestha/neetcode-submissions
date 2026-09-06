class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        const int INF = 2147483647;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (const auto& dir : directions) {
                int row = r + dir[0];
                int col = c + dir[1];
                if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == INF) {
                    grid[row][col] = grid[r][c] + 1;
                    q.push({row, col});
                }
            }
        }
    }
};