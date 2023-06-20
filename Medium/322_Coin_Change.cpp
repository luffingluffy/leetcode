// Top down:
class Solution {
   public:
    const int INF = 1e9;

    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -1);

        // Base case
        if (amount == 0) {
            return 0;
        }
        if (memo[amount] != -1) {
            return memo[amount];
        }

        // DP
        int ans = INF;
        for (int coin : coins) {
            if (amount >= coin) {
                ans = min(ans, coinChange(coins, amount - coin) + 1);
            }
        }

        memo[amount] = ans;
        return memo[amount];
    }
};

// Bottom up:
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, 1e6);
        memo[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    memo[i] = min(memo[i], 1 + memo[i - coins[j]]);
                }
            }
        }

        return memo[amount] == 1e6 ? -1 : memo[amount];
    }
};