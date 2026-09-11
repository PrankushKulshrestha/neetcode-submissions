class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        word[i] = c;
                        if (word == endWord) return steps + 1;
                        if (words.count(word)) {
                            q.push(word);
                            words.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            steps++;
        }
        return 0;
    }
};
