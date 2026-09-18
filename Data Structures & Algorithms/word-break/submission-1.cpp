class Solution {
public:
    // Bottom Up DP
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        // memoize result of whether we can segment string i->end()
        vector<bool> dp(s.length() + 1, false);
        dp[s.length()] = true; // empty string is valid

        for(int i = s.length() - 1; i >= 0; i--)
        {
            for(const string& word : wordDict)
            {
                // if s[i] -> s[i + len(word)] is a word, update dp table
                if (i + word.length() <= s.length())
                {
                    if (s.substr(i, word.length()) == word)
                    {
                        // dp[i] is breakable, but whether the whole segment through
                        // the end of the string is breakable depends on the next word as well
                        dp[i] = dp[i + word.length()];
                    }
                }
                if (dp[i]) break; // early break to avoid redundant computation
            }
        }
        return dp[0];
    }
};
