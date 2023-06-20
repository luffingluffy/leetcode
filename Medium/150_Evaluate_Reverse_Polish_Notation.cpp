class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string s : tokens) {
            if (isdigit(s.back())) {
                st.push(stoi(s));
            } else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if (s[0] == '+') {
                    st.push(num1 + num2);
                } else if (s[0] == '-') {
                    st.push(num1 - num2);
                } else if (s[0] == '*') {
                    st.push(num1 * num2);
                } else {
                    st.push(num1 / num2);
                }
            }
        }

        return st.top();
    }
};