class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int curr = 0, l = 0, r = nums.size() - 1;

        while (curr <= r) {
            if (nums[curr] == 0) {
                swap(nums[curr++], nums[l++]);
            } else if (nums[curr] == 2) {
                swap(nums[curr], nums[r--]);
            } else {
                curr++;
            }
        }
    }
};