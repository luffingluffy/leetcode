// Top down:
class Solution {
   public:
    bool dp(vector<int>& nums, int n, int subset_sum, vector<vector<int>>& memo) {
        if (subset_sum == 0) return true;
        if (n == 0 || subset_sum < 0) return false;

        if (memo[n][subset_sum] != -1) return memo[n][subset_sum];

        return memo[n][subset_sum] = dp(nums, n - 1, subset_sum - nums[n - 1], memo) || dp(nums, n - 1, subset_sum, memo);
    }

    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0), subset_sum = total_sum / 2;
        if (total_sum % 2) return false;

        int n = nums.size() - 1;
        vector<vector<int>> memo(n + 1, vector<int>(subset_sum + 1, -1));

        return dp(nums, n, subset_sum, memo);
    }
};

// Bottom up:
