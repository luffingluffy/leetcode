class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, ans = 0;
        for (int x : prices) {
            min_price = min(min_price, x);
            ans = max(ans, x - min_price);
        }

        return ans;
    }
};