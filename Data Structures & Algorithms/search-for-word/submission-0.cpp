class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        function<bool(int, int, int)> dfs = [&](int r, int c, int i) {
            if (i == word.size()) {
                return true;
            }
            if (r < 0 || r >= rows || c < 0 || c >= cols ||
                board[r][c] != word[i]) {
                return false;
            }
            char temp = board[r][c];
            board[r][c] = '#';
            bool found =
                dfs(r + 1, c, i + 1) ||
                dfs(r - 1, c, i + 1) ||
                dfs(r, c + 1, i + 1) ||
                dfs(r, c - 1, i + 1);
            board[r][c] = temp;

            return found;
        };
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};