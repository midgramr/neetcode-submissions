#define sz(a) (int)(a).size()

class Solution {
    // Starting a separate BFS from each cell would be too slow; better to do it from the outside working in
    // Do 2 separate BFSes: one from the pacific side and another from the atlantic side
    // Working backward: a neighboring cell can flow to the current one if heights[i] <= heights[neighbor]
    vector<pair<int,int>> off{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = sz(heights), n = sz(heights[0]);
        vector<vector<bool>> pacific(m, vector<bool>(n)), atlantic(m, vector<bool>(n));

        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) {
            q.push({i, 0});
            pacific[i][0] = true;
        }
        for (int j = 1; j < n; ++j) {
            q.push({0, j});
            pacific[0][j] = true;
        }

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (auto [di, dj] : off) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n
                    || heights[ni][nj] < heights[i][j] || pacific[ni][nj])
                    continue;
                pacific[ni][nj] = true;
                q.push({ni, nj});
            }
        }

        q = queue<pair<int,int>>();
        for (int i = 0; i < m; ++i) {
            q.push({i, n - 1});
            atlantic[i][n - 1] = true;
        }
        for (int j = 0; j < n - 1; ++j) {
            q.push({m - 1, j});
            atlantic[m - 1][j] = true;
        }
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (auto [di, dj] : off) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n
                    || heights[ni][nj] < heights[i][j] || atlantic[ni][nj])
                    continue;
                atlantic[ni][nj] = true;
                q.push({ni, nj});
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
