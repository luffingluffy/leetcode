// Bit Manipulation
class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= n - 1;
            ans++;
        }

        return ans;
    }
};

// Loop
class Solution {
   public:
    int hammingWeight(uint32_t n) {
        string s = bitset<32>(n).to_string();

        int ans = 0;
        for (auto c : s) {
            if (c == '1') ans++;
        }

        return ans;
    }
};