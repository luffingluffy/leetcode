class Solution {
   public:
    const vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& image, int r, int c, int curr_color, int new_color) {
        if (image[r][c] == curr_color) {
            image[r][c] = new_color;

            for (auto [i, j] : dir) {
                int dr = r + i, dc = c + j;
                if (dr >= 0 && dr < image.size() && dc >= 0 && dc < image[0].size()) {
                    dfs(image, dr, dc, curr_color, new_color);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), init_color = image[sr][sc];

        if (init_color == color) {
            return image;
        }

        // BFS:
        queue<pair<int, int>> q;
        pair<int, int> start = {sr, sc};
        q.push(start);
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            int& curr_color = image[curr.first][curr.second];
            if (curr_color == init_color) {
                curr_color = color;

                for (auto [i, j] : dir) {
                    int dr = curr.first + i, dc = curr.second + j;
                    if (dr >= 0 && dr < m && dc >= 0 && dc < n) {
                        q.push({dr, dc});
                    }
                }
            }
        }

        return image;

        // DFS:
        // if (image[sr][sc] == color) {
        //     return image;
        // }

        // dfs(image, sr, sc, image[sr][sc], color);
        // return image;
    }
};