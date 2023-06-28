// Using STL:
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = {nums};
        while (next_permutation(nums.begin(), nums.end())) {
            ans.push_back(nums);
        }

        return ans;
    }
};

// Backtracking:
class Solution {
   public:
    void backtrack(vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(curr.begin(), curr.end(), nums[i]) == curr.end()) {
                curr.push_back(nums[i]);
                backtrack(curr, ans, nums);
                curr.pop_back();
            }
        }
    };

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtrack(curr, ans, nums);

        return ans;
    }
};