class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int num_rows = heights.size();
        int num_cols = heights[0].size();

        vector<vector<bool>> atlantic(num_rows, vector<bool>(num_cols, false));
        vector<vector<bool>> pacific(num_rows, vector<bool>(num_cols, false));

        // start from top and bottom border
        for (int i = 0; i < num_cols; i++) {
            dfs(heights, 0, i, pacific, 0);
            dfs(heights, num_rows - 1, i, atlantic, 0);
        }

        // start from left and right border
        for (int i = 0; i < num_rows; i++) {
            dfs(heights, i, 0, pacific, 0);
            dfs(heights, i, num_cols - 1, atlantic, 0);
        }

        // collect all pairs that can be reach by both
        vector<vector<int>> result;
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    result.push_back({i, j});
                }
            } 
            
        }
        return result;
    }
private:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // thresh is minimum next cell has to have
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited, int thresh) {
        int num_rows = heights.size();
        int num_cols = heights[0].size();
        
        // out of bounds or visited
        if (r < 0 || r >= num_rows || c < 0 || c >= num_cols || visited[r][c]) return;

        // new val is lower than threshold -> can't flow from this value to the ocean
        if (heights[r][c] < thresh) return;

        // this coordinate can be reached
        visited[r][c] = true;

        // recurse to neighbors
        for (const auto& [row_change, col_change]: directions) {
            int new_row = r + row_change;
            int new_col = c + col_change;

            dfs(heights, new_row, new_col, visited, heights[r][c]);
        }
    }
};
