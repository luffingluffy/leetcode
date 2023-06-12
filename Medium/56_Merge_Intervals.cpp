class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        ans.push_back(intervals.back());
        return ans;
    }
};