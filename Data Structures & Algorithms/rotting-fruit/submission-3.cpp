#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int step = 0;
        int fresh = 0;

        std::vector<std::vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 1) {
                    ++fresh;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty() && fresh != 0) {
            int n = q.size();
            ++step;

            for (int i = 0; i < n; ++i) {
                // Fixed: Changed 'const auto&' to 'auto' to copy values before q.pop()
                auto [fir, sec] = q.front();
                q.pop();

                for (const auto& direction : directions) {
                    int nx = direction[0] + fir;
                    int ny = direction[1] + sec;

                    if (nx < 0 || nx >= ROWS ||
                        ny < 0 || ny >= COLS ||
                        grid[nx][ny] != 1) {
                        continue;
                    }

                    --fresh;
                    q.push({nx, ny});
                    grid[nx][ny] = 2;
                }
            }
        }

        return fresh == 0 ? step : -1;
    }
};