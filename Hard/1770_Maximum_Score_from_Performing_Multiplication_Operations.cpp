class Solution {
    public:
    int memo[1001][1001] = {};
    int dp(vector<int>& nums, vector<int>& mults, int l, int i) {
        if (i >= mults.size())
            return 0;
        if (!memo[l][i]) {
            int r = nums.size() - 1 - (i - l);
            memo[l][i] = max(nums[l] * mults[i] + dp(nums, mults, l + 1, i + 1), 
                    nums[r] * mults[i] + dp(nums, mults, l, i + 1));
        }
    return memo[l][i];
    }

    int maximumScore(vector<int>& nums, vector<int>& mults) {
        return dp(nums, mults, 0, 0);
    }
};

