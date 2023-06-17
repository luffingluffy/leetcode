class Solution {
   public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (auto d : dir) {
                int dr = curr.first + d[0], dc = curr.second + d[1];
                if (dr >= 0 && dc >= 0 && dr < m && dc < n) {
                    if (ans[dr][dc] > ans[curr.first][curr.second] + 1) {
                        ans[dr][dc] = ans[curr.first][curr.second] + 1;
                        q.push({dr, dc});
                    }
                }
            }
        }

        return ans;
    }
};