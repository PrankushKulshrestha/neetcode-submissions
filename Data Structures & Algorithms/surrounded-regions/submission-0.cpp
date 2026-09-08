class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int rows = board.size();
        int cols = board[0].size();
        auto dfs = [&](auto& self, int r, int c) -> void {
            if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') {
                return;
            }
            board[r][c] = 'T';
            self(self, r + 1, c);
            self(self, r - 1, c);
            self(self, r, c + 1);
            self(self, r, c - 1);
        };
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && board[r][c] == 'O') {
                    dfs(dfs, r, c);
                }
            }
        }
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};