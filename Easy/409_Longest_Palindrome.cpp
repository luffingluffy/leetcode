class Solution {
   public:
    int longestPalindrome(string s) {
        int freq[128] = {};
        for (auto c : s) {
            freq[c - 'A']++;
        }

        int ans = 0, has_odd = 0;
        for (int i : freq) {
            if (i % 2 == 0) {
                ans += i;
            } else {
                ans += i - 1;
                has_odd = 1;
            }
        }

        return has_odd ? ans + 1 : ans;
    }
};