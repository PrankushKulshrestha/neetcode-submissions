#include <array>
#include <string>

class TrieNode {
public:
    bool word;
    std::array<TrieNode*, 26> children;

    TrieNode() {
        for(int i{ 0 }; i < 26; ++i) children[i] = nullptr;
        word = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(int idx, TrieNode* cur, std::string& word) {
        if(idx == word.length()) return cur->word;
        bool found{ false };
        if(word[idx] == '.') {
            for(int i{ 0 }; i < 26; ++i) {
                if(cur->children[i]) {
                    found |= dfs(idx + 1, cur->children[i], word);
                }
            }
        } else if(cur->children[word[idx] - 'a']) {
            found |= dfs(idx + 1, cur->children[word[idx] - 'a'], word);
        }
        return found;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(std::string& word) {
        TrieNode* cur{ root };
        for(char c : word) {
            if(!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->word = true;
    }
    
    bool search(std::string& word) {
        return dfs(0, root, word);
    }
};
