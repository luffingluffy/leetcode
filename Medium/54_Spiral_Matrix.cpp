class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int top_border = 0, bottom_border = m - 1;
        int left_border = 0, right_border = n - 1;

        vector<int> ans;
        while (ans.size() < m * n) {
            // left to right
            for (int i = left_border; i <= right_border; i++) {
                ans.push_back(matrix[top_border][i]);
            }
            top_border++;

            // top to bottom
            for (int i = top_border; i <= bottom_border; i++) {
                ans.push_back(matrix[i][right_border]);
            }
            right_border--;

            // right to left
            if (top_border - 1 != bottom_border) {
                for (int i = right_border; i >= left_border; i--) {
                    ans.push_back(matrix[bottom_border][i]);
                }
                bottom_border--;
            }

            // bottom to top
            if (left_border != right_border + 1) {
                for (int i = bottom_border; i >= top_border; i--) {
                    ans.push_back(matrix[i][left_border]);
                }
                left_border++;
            }
        }

        return ans;
    }
};