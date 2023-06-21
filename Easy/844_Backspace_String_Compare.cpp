// Stack:
class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#' && !st1.empty()) {
                st1.pop();
            } else if (s[i] != '#') {
                st1.push(s[i]);
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#' && !st2.empty()) {
                st2.pop();
            } else if (t[i] != '#') {
                st2.push(t[i]);
            }
        }

        return st1 == st2;
    }
};

// Pointers:
class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        while (i >= 0 || j >= 0) {
            int s_del = 0, t_del = 0;
            while (i >= 0 && (s_del || s[i] == '#')) {
                s_del += (s[i] == '#') ? 1 : -1;
                i--;
            }
            while (j >= 0 && (t_del || t[j] == '#')) {
                t_del += (t[j] == '#') ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            i--;
            j--;
        }

        return true;
    }
};