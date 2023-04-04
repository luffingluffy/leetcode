class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            int other_pair = target - nums[i];
            
            // if other pair in map
            if (m.find(other_pair) != m.end()) {
                ans.push_back(m[other_pair]);
                ans.push_back(i);
                return ans;
            } else {
                m[nums[i]] = i;   
            }
        }
        
        return ans;
    }
};