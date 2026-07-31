class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<pair<int, int>>> achk(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '1') {
                    achk[0].push_back({i + 1, j + 1});
                }
                if (board[i][j] == '2') {
                    achk[1].push_back({i + 1, j + 1});
                }
                if (board[i][j] == '3') {
                    achk[2].push_back({i + 1, j + 1});
                }
                if (board[i][j] == '4') {
                    achk[3].push_back({i + 1, j + 1});
                }
                if (board[i][j] == '5') {
                    achk[4].push_back({i + 1, j + 1});
                }
                if (board[i][j] == '6') {
                    achk[5].push_back({i + 1, j + 1});
                }
                if (board[i][j] == '7') {
                    achk[6].push_back({i + 1, j + 1});
                }
                if (board[i][j] == '8') {
                    achk[7].push_back({i + 1, j + 1});
                }
                if (board[i][j] == '9') {
                    achk[8].push_back({i + 1, j + 1});
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < achk[i].size(); j++) {
                for (int k = j + 1; k < achk[i].size(); k++) {
                    int r1 = achk[i][j].first;
                    int c1 = achk[i][j].second;
                    int r2 = achk[i][k].first;
                    int c2 = achk[i][k].second;
                    if (r1 == r2) return false;
                    if (c1 == c2) return false;
                    if ((r1 - 1) / 3 == (r2 - 1) / 3 &&
                        (c1 - 1) / 3 == (c2 - 1) / 3)
                        return false;
                }
            }
        }
        return true;
    }
};