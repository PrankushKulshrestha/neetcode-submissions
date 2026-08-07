class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        st.reserve(tokens.size());
        for (const string& token : tokens) {
            if (token.size() == 1 &&
                (token[0] == '+' || token[0] == '-' ||
                 token[0] == '*' || token[0] == '/')) {
                int b = st.back();
                st.pop_back();
                int a = st.back();
                st.pop_back();
                switch (token[0]) {
                    case '+': st.push_back(a + b); break;
                    case '-': st.push_back(a - b); break;
                    case '*': st.push_back(a * b); break;
                    case '/': st.push_back(a / b); break;
                }
            } else {
                int num;
                from_chars(token.data(), token.data() + token.size(), num);
                st.push_back(num);
            }
        }
        return st.back();
    }
};