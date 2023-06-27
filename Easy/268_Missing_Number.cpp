// Gauss Formula:
class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);

        return n * (n + 1) / 2 - sum;
    }
};

// Bit Manipulation:
class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            ans ^= i ^ nums[i];
        }

        return ans;
    }
};