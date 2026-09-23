class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        function<int(int,int)> dfs = [&](int r, int c) {
            if (dp[r][c]) return dp[r][c];
            dp[r][c] = 1;
            for (auto [dr, dc] : dir) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c])
                    dp[r][c] = max(dp[r][c], 1 + dfs(nr, nc));
            }
            return dp[r][c];
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(i, j));
        return ans;
    }
};
