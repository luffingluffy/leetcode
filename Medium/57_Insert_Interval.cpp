class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idx = lower_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        if (idx == intervals.size()) {
            intervals.push_back(newInterval);
        } else {
            intervals.insert(intervals.begin() + idx, newInterval);
        }

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (ans.back()[0] <= intervals[i][0] && ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};