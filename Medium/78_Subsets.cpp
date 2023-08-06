// Iterative:
class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        for (int num : nums) {
            // Store the current size of the output vector
            int n = ans.size();

            // Iterate over the first n subsets in the output vector
            for (int i = 0; i < n; i++) {
                // Duplicate the current subset by appending a copy to the end of the output vector
                ans.push_back(ans[i]);
                // Append the current element to the last subset in the output vector
                ans.back().push_back(num);
            }
        }

        return ans;
    }
};

// Backtracking:
class Solution {
   public:
    int n, k;
    vector<vector<int>> ans = {};

    void backtrack(int first, vector<int>& curr, vector<int>& nums) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for (int i = first; i < n; i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, curr, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        for (k = 0; k <= n; k++) {
            vector<int> temp;
            backtrack(0, temp, nums);
        }

        return ans;
    }
};