class MinStack {
public:
    stack<int> st;
    stack<int> mn;

    MinStack() {
    }
    void push(int val) {
        st.push(val);

        if (mn.empty())
            mn.push(val);
        else
            mn.push(min(val, mn.top()));
    }
    void pop() {
        st.pop();
        mn.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return mn.top();
    }
};