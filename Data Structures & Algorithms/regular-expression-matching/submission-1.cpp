class Solution {
public:
    bool isMatch(string s, string p) {
        vector<int> pos(s.size() + 1);
        pos[s.size()] = 1;
        for (int i = p.size() - 1; i >= 0; i--) {
            if (p[i] == '*') {
                if (p[i - 1] == '.') {
                    for (int j = s.size() - 1; j >= 0; j--) {
                        pos[j] |= pos[j + 1];
                    }
                }
                else {
                    for (int j = s.size() - 1; j >= 0; j--) {
                        if (p[i - 1] == s[j])
                            pos[j] |= pos[j + 1];
                    }
                }
                i--;
            }
            else if (p[i] == '.') {
                for (int j = 0; j <= s.size(); j++) {
                    if (j < s.size())
                        pos[j] = pos[j + 1];
                    else
                        pos[j] = 0;
                }
            }
            else {
                for (int j = 0; j <= s.size(); j++) {
                    if (j < s.size() && p[i] == s[j])
                        pos[j] = pos[j + 1];
                    else
                        pos[j] = 0;
                }
            }
        }
        return pos[0];
    }
};
