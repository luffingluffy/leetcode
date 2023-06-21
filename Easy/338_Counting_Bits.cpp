// DP from last bit set: P(x) = P(x & (x − 1)) + 1
class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;
    }
};

// DP from least significant bit: P(x) = P(x / 2) + (x mod 2)
class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            ans[x] = ans[x >> 1] + (x & 1);  // x / 2 is x >> 1 and x % 2 is x & 1
        }

        return ans;
    }
};