class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else {
                max_profit = max(max_profit, prices[i] - buy);
            }
        }

        return max_profit;
    }
};