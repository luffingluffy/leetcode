class Solution {
   public:
    void helper(vector<int>& nums, int i, vector<vector<int>>& ans) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                ++left;
            } else if (sum > 0) {
                --right;
            } else {
                ans.push_back({nums[i], nums[left++], nums[right--]});
                while (left < right && nums[left] == nums[left - 1])  // avoid duplicates
                    ++left;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {  // skip if curr == prev
                helper(nums, i, ans);
            }

        return ans;
    }
};