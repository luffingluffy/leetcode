class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m = {
            {')', '('},
            {'}', '{'},
            {']', '['}};

        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if (!st.empty() && st.top() == m[c]) {
                st.pop();
            } else
                return false;
        }

        return st.empty();
    }
};