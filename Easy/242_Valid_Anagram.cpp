class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26);
        for (char c : s) {
            freq[c - 'a']++;
        }
        for (char c : t) {
            if (freq[c - 'a'] < 1) {
                return false;
            }
            freq[c - 'a']--;
        }

        return (accumulate(freq.begin(), freq.end(), 0)) ? false : true;
    }
};