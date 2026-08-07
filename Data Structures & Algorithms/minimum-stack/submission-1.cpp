class MinStack {
public:
    stack<pair<int, int>>st;
    int m;
    MinStack() {
        m = INT_MAX;
    }
    void push(int val) {
        m = min(m, val);
        st.push({val, m});
    }
    void pop() {
        st.pop();
        if (!st.empty())
            m = st.top().second;
        else 
            m = INT_MAX;
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};
