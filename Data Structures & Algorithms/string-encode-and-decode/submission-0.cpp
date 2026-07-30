class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (string &str : strs) {
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            j++;
            decoded.push_back(s.substr(j, len));
            i = j + len;
        }
        return decoded;
    }
};