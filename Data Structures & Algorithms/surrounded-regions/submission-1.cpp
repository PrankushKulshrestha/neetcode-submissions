class Solution {
public:
    int m, n;
    bool isValid(int i, int j) {
        if(i >= 0 && i < m && j >= 0 && j < n) return true;
        return false;
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        queue<pair<int, int>> ind;
        int r, c;
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                ind.push({i, 0});
            }
            if(board[i][n-1] == 'O') {
                ind.push({i, n-1});
            }
        }

        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                ind.push({0, j});
            }
            if(board[m-1][j] == 'O') {
                ind.push({m-1, j});
            }
        }

        while(ind.size()) {
            r = ind.front().first;
            c = ind.front().second;
            ind.pop();
            board[r][c] = 'K';

            if(isValid(r-1, c) && board[r-1][c] == 'O') {
                
                board[r-1][c] = 'K';
                ind.push({r-1, c});
            }

            if(isValid(r+1, c) && board[r+1][c] == 'O') {
                board[r+1][c] = 'K';
                ind.push({r+1, c});
            }
            if(isValid(r, c-1) && board[r][c-1] == 'O') {
                board[r][c-1] = 'K';
                ind.push({r, c-1});
            }
            if(isValid(r, c+1) && board[r][c+1] == 'O') {
                board[r][c+1] = 'K';
                ind.push({r, c+1});
            }

        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'K') {
                    board[i][j] = 'O';
                }
            }
        }
    
    }
};
