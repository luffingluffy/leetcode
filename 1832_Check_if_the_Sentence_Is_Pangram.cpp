class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> str(sentence.begin(), sentence.end());
        return str.size() == 26;
    }
};