class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0, max_sum = -INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (curr_sum < 0) curr_sum = 0;
            curr_sum += nums[i];
            max_sum = max(curr_sum, max_sum);
        }

        return max_sum;
    }
};