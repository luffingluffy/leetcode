class Solution {
   public:
    vector<int> memo;
    vector<string> wordDict;
    string s;

    bool dp(int i) {
        if (i < 0) return true;
        if (memo[i] != -1) return memo[i];

        for (string w : wordDict) {
            int n = w.length();
            if (i - n + 1 < 0) continue;
            if (s.substr(i - n + 1, n) == w && dp(i - n)) {
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector(s.size(), -1);
        this->wordDict = wordDict;
        this->s = s;

        return dp(s.size() - 1);
    }
};