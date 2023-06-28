// Sorting:
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        transform(nums.begin(), nums.end(), nums.begin(), [](int& i) { return pow(i, 2); });
        sort(nums.begin(), nums.end());

        return nums;
    }
};

// Two Pointers (Inside-out):
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int abs_min = INT_MAX, idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) < abs_min) {
                abs_min = abs(nums[i]);
                idx = i;
            }
        }
        vector<int> ans = {(int)pow(nums[idx], 2)};

        int i = idx - 1, j = idx + 1;
        while (i >= 0 || j < nums.size()) {
            if (i < 0) {
                ans.push_back(pow(nums[j++], 2));
            } else if (j >= nums.size()) {
                ans.push_back(pow(nums[i--], 2));
            } else if (abs(nums[i]) < abs(nums[j])) {
                ans.push_back(pow(nums[i--], 2));
            } else {
                ans.push_back(pow(nums[j++], 2));
            }
        }

        return ans;
    }
};

// Two Pointers (Outside-in):
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int i = 0, j = n - 1, k = n - 1;
        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                ans[k--] = pow(nums[i], 2);
                i++;
            } else {
                ans[k--] = pow(nums[j], 2);
                j--;
            }
        }

        return ans;
    }
};