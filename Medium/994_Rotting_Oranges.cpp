class Solution {
   public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh_count++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        if (!fresh_count) return 0;

        int ans = -1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto curr = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int dr = curr.first + dir[d][0], dc = curr.second + dir[d][1];
                    if (dr >= 0 && dc >= 0 && dr < m && dc < n && grid[dr][dc] == 1) {
                        grid[dr][dc] = 2;
                        fresh_count--;
                        q.push({dr, dc});
                    }
                }
            }

            ans++;
        }

        return fresh_count ? -1 : ans;
    }
};