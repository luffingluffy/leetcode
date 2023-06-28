class Solution {
   public:
    void backtrack(int start, int remainder, vector<int>& candidates, vector<int>& combination, vector<vector<int>>& ans) {
        if (remainder == 0) {
            ans.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size() && candidates[i] <= remainder; i++) {
            combination.push_back(candidates[i]);
            // Try same value
            backtrack(i, remainder - candidates[i], candidates, combination, ans);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, combination, ans);

        return ans;
    }
};