class Solution {
private:
    int topdown(vector<vector<int>> &cache, int col, int row, int m, int n) {
        if (col >= m || row >= n) return 0;
        if (col == m - 1 && row == n - 1) return 1;
        if (cache[col][row]) return cache[col][row];
        return cache[col][row] = topdown(cache, col, row + 1, m, n) + topdown(cache, col + 1, row, m, n);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, 0));
        cache[m - 1][n - 1] = 1;
        return topdown(cache, 0, 0, m, n);
    }
};