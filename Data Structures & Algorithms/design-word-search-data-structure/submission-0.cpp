class WordDictionary {
   private:
    struct TrieNode {
        TrieNode* children[26];
        bool isWord;
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    bool dfs(TrieNode* node, const string& word, int index) {
        if (index == word.size()) {
            return node->isWord;
        }
        char c = word[index];
        if (c != '.') {
            int i = c - 'a';

            if (node->children[i] == nullptr) {
                return false;
            }

            return dfs(node->children[i], word, index + 1);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                if (dfs(node->children[i], word, index + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

   public:
    WordDictionary() { root = new TrieNode(); }
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->children[i] == nullptr) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->isWord = true;
    }
    bool search(string word) { return dfs(root, word, 0); }
};
