class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int min = 0, max = nums.size() - 1;
        
        while (min <= max) {
            int mid = min + (max - min) / 2;
            
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) max = mid - 1;
            else min = mid + 1;
        }
        return min;
    }
};