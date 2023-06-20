class MinStack {
   public:
    stack<int> st;
    int min_val;

    MinStack() {
        min_val = INT_MAX;
    }

    void push(int val) {
        if (val <= min_val) {
            st.push(min_val);
            min_val = val;
        }
        st.push(val);
    }

    void pop() {
        if (st.top() == min_val) {
            st.pop();
            min_val = st.top();
        }
        st.pop();
        if (st.empty()) {
            min_val = INT_MAX;
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_val;
    }
};