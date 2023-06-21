// DFS:
class Solution {
   public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        for (int d = 0; d < 4; d++) {
            int dr = dir[d][0] + i, dc = dir[d][1] + j;
            if (dr >= 0 && dr < grid.size() && dc >= 0 && dc < grid[0].size()) {
                if (grid[dr][dc] == '1') {
                    dfs(dr, dc, grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};

// BFS:
