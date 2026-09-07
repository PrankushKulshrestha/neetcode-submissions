#include <vector>
class Solution {
   private:
    void dfs(int r, int c, int prevHeight, const std::vector<std::vector<int>>& heights,
             std::vector<std::vector<bool>>& visited) {
        int rows = heights.size();
        int cols = heights[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] ||
            heights[r][c] < prevHeight) {
            return;
        }
        visited[r][c] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            dfs(r + dr[i], c + dc[i], heights[r][c], heights, visited);
        }
    }

   public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int rows = heights.size();
        int cols = heights[0].size();
        std::vector<std::vector<bool>> pacific(rows, std::vector<bool>(cols, false));
        std::vector<std::vector<bool>> atlantic(rows, std::vector<bool>(cols, false));
        for (int c = 0; c < cols; ++c) {
            dfs(0, c, heights[0][c], heights, pacific);
            dfs(rows - 1, c, heights[rows - 1][c], heights, atlantic);
        }
        for (int r = 0; r < rows; ++r) {
            dfs(r, 0, heights[r][0], heights, pacific);
            dfs(r, cols - 1, heights[r][cols - 1], heights, atlantic);
        }
        std::vector<std::vector<int>> result;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};