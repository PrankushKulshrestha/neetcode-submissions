class Solution {
    struct Node 
    {
        Node* child[26]{};
        string word = "";
    };
    Node* root = new Node();
    vector<string> ans;
    int m, n;
    void dfs(vector<vector<char>>& board, int r, int c, Node* node) {
if (r < 0 || r >= m || c < 0 || c >= n ||board[r][c] == '#' || !node->child[board[r][c] - 'a'])
            return;
        char ch = board[r][c];
        Node* next = node->child[ch - 'a'];
        if (!next->word.empty()) 
        {
            ans.push_back(next->word);
            next->word.clear(); 
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
        for (string& word : words) 
        {
            Node* cur = root;
            for (char ch : word) 
            {
                int i = ch - 'a';
                if (!cur->child[i])
                    cur->child[i] = new Node();
                cur = cur->child[i];
            }
            cur->word = word;
        }
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
                dfs(board, i, j, root);
            
        }
        return ans;
    }
};