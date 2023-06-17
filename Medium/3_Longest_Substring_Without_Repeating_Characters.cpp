class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> m;

        for (int i = 0, j = 0; j < s.size(); j++) {
            if (m.find(s[j]) != m.end()) {
                i = max(m[s[j]] + 1, i);
            }

            m[s[j]] = j;
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};