// Rewrite zeroes (Sub-optimal)
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), num_zeroes = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                num_zeroes++;
            } else {
                nums[i - num_zeroes] = nums[i];
            }
        }

        for (int i = n - num_zeroes; i < n; i++) {
            nums[i] = 0;
        }
    }
};

// Swap non-zeroes with zeroes found earlier (Optimal as it only writes when necessary)
void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}