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