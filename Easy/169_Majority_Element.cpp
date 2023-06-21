// Hashmap:
class Solution {
   public:
    unordered_map<int, int> mp;
    int majorityElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                mp[nums[i]]++;
            } else {
                mp.insert({nums[i], 1});
            }

            if (mp[nums[i]] > nums.size() / 2) return nums[i];
        }

        return -1;
    }
};

// Sorting:
class Solution {
   public:
    unordered_map<int, int> mp;
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};