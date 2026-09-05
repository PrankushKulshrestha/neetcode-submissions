class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '0') continue;
                if(grid[i][j] == '5') continue;
                dfs(grid, i, j);
                count++;
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return;
        if(grid[r][c] == '0' || grid[r][c] == '5') return;
        grid[r][c] = '5';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
};
