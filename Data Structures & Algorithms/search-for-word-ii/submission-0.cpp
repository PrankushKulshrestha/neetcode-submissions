class Solution {
    struct TrieNode {
        TrieNode* child[26];
        string word;
        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    vector<string> ans;
    int m, n;
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        char ch = board[r][c];
        if (ch == '#') return;
        int idx = ch - 'a';
        if (node->child[idx] == nullptr) return;
        TrieNode* next = node->child[idx];
        if (!next->word.empty()) {
            ans.push_back(next->word);
            next->word = "";
        }
        board[r][c] = '#';
        dfs(board, r + 1, c, next);
        dfs(board, r - 1, c, next);
        dfs(board, r, c + 1, next);
        dfs(board, r, c - 1, next);
        board[r][c] = ch;
    }

   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        root = new TrieNode();
        for (string& word : words) {
            TrieNode* curr = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (curr->child[idx] == nullptr) {
                    curr->child[idx] = new TrieNode();
                }
                curr = curr->child[idx];
            }
            curr->word = word;
        }
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dfs(board, r, c, root);
            }
        }
        return ans;
    }
};
